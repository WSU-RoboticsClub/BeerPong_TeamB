#include "BeerPong.h"

extern char uart_rx_buffer[BUFFER_SIZE], uart_tx_buffer [BUFFER_SIZE];
extern volatile int sync;
extern const char KEY;

//Motor Variables
extern volatile long M1_RPM_goal,
M2_RPM_goal,
M1_RPM_status,
M2_RPM_status;
volatile int timeout;
void timeOut_sync();

int convert_to_int(uint8 *message);


void establishUART()
{
	UART_Config ucon = {0};
	
	ucon.speed = 115200;
	ucon.pb_clk = PB_CLK;
	ucon.rx_buffer_ptr = uart_rx_buffer;
	ucon.rx_buffer_size = BUFFER_SIZE;
	ucon.rx_callback = NULL;
	ucon.rx_en = TRUE;
	ucon.tx_buffer_ptr = uart_tx_buffer;
	ucon.tx_buffer_size = BUFFER_SIZE;
	ucon.tx_callback = NULL;
	ucon.tx_en = TRUE;
	initialize_UART(ucon);
	
	Packetizer_Config pcon = {0};
	pcon.callback = &packetizer_callback;
	pcon.control_byte = '!';
	pcon.uart_config = ucon;
	pcon.which_channel = PACKET_UART_CH_1;
	initialize_packetizer(pcon);
}

void acquireSynchronization()
{
	int i = 0;
	
	//Initialize Timer_1 to be used as a form of timeout. If we have not received messages back from the CPU
	//by the time its interrupt fires, we will retry
	Timer_Config t1 = {0};
	t1.callback = &timeOut_sync;
	t1.enabled = TRUE;
	t1.frequency = 1;
	t1.pbclk = PB_CLK;
	t1.which_timer = TIMER_1;
	initialize_Timer(t1);
	char key = KEY;
	
	while (!sync)
	{
		//Enqueue SYNC_COUNT of KEY messages into the UART transmission queue to be packetized
		for (i = 0; i < SYNC_COUNT; i++) {
			send_packet(PACKET_UART_CH_1, &key, sizeof(key));
		}
		
		//Now, we will wait for either a time out or a proper response from the
		while (timeout == 0 && sync == 0)
		{
			bg_process_packetizer(PACKET_UART_CH_1); //process received messages
		}
		
		//If we got sync, disable timer - otherwise reset timeout and try again
		if (sync)
		disable_Timer(TIMER_1);
		else
		timeout = 0;
	}
	configureSystemTimer();
}

void packetizer_callback(uint8 *message, uint8 size)
{
	
	
	//Reset Timer 4s count because we still have sync
	//TMR4 = 0;
	
	//If we are simply syncing, we need to check the received message
	if (sync == 0)
	{
		if (size > 0)
		{
			if (message[0] == KEY && size == sizeof(KEY))
			sync = 1;
		}
	}
	else
	{
		if (size > 0)
		{
			switch (message[0]) {
				case M1_SET_RPM:
				//Update the RPM Setting for M1
				if (size >= 5)
				M1_RPM_goal = convert_to_int(&(message[1]));
				break;
				case M2_SET_RPM:
				//Update the RPM Setting for M2
				if (size >= 5)
				M2_RPM_goal = convert_to_int(&(message[1]));
				break;
				case M1_READ_RPM:
				//Transmit the current RPMs for M1
				send_packet(PACKET_UART_CH_1, &M1_RPM_status, sizeof(M1_RPM_status));
				break;
				case M2_READ_RPM:
				//Transmit the current RPMs for M2
				send_packet(PACKET_UART_CH_1, &M2_RPM_status, sizeof(M2_RPM_status));
				break;
				default:
				break;
			}
		}
	}
}

void timeOut_sync()
{
	timeout = 1;
}

int convert_to_int(uint8 *message)
{
	int response = 0, i = 0;
	
	for (i = 0; i < 4; i++)
	response |= message[i]<<(8*i);
	
	return response;
}

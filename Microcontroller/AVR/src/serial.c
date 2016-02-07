#include "BeerPong.h"

//Serial Variables	
uint8_t uart_rx_buffer[BUFFER_SIZE], uart_tx_buffer [BUFFER_SIZE]; //Serial buffers

//Motor Variables
extern volatile uint32_t M1_RPM_status,
	   M2_RPM_status;

extern uint32_t M1_dutyCycle, M2_dutyCycle;

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

void packetizer_callback(uint8 *message, uint8 size)
{
	DDRB |= 1<<4;

	if (size > 0)
	{
		switch (message[0]) {
			case M1_SET_DUTYCYCLE:
				//Update the duty Setting for M1
				if (size >= 5)
				{
					memcpy(&M1_dutyCycle, &(message[1]), 4);
					update_PWM(PWM_CH_1A_SIMPLE, ((float)M1_dutyCycle)/100);
				}
				break;
			case M2_SET_DUTYCYCLE:
				//Update the duty Setting for M2
				if (size >= 5)
				{
					memcpy(&M2_dutyCycle, &(message[1]), 4);
					update_PWM(PWM_CH_1B_SIMPLE, ((float)M2_dutyCycle)/100);
				}
				break;
			default:
				break;
		}
	}
}


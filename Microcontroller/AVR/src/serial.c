#include "BeerPong.h"

extern uint8_t uart_rx_buffer[BUFFER_SIZE], uart_tx_buffer [BUFFER_SIZE];

//Motor Variables
extern volatile long M1_RPM_goal,
	   M2_RPM_goal,
	   M1_RPM_status,
	   M2_RPM_status;
volatile int timeout;

long convert_to_int(uint8 *message);

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
	
	char packet[256];

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
				memcpy(&(packet[1]), (const void *) &M1_RPM_status, sizeof(M1_RPM_status));
				packet[0] = message[0];
				send_packet(PACKET_UART_CH_1, (uint8 *)packet, 1+sizeof(M1_RPM_status));
				break;
			case M2_READ_RPM:
				//Transmit the current RPMs for M2
				memcpy(&(packet[1]),(const void *) &M2_RPM_status, sizeof(M2_RPM_status));
				packet[0] = message[0];
				send_packet(PACKET_UART_CH_1, (uint8 *)packet, 1+sizeof(M1_RPM_status));
				break;
			case M1_READ_GOAL:
				memcpy(&(packet[1]), (const void *)&M1_RPM_goal, sizeof(M1_RPM_goal));
				packet[0] = message[0];
				send_packet(PACKET_UART_CH_1, (uint8 *)packet, 1+sizeof(M1_RPM_status));
				break;
			case M2_READ_GOAL:
				memcpy(&(packet[1]), (const void *)&M2_RPM_goal, sizeof(M2_RPM_goal));
				packet[0] = message[0];
				send_packet(PACKET_UART_CH_1, (uint8 *)packet, 1+sizeof(M1_RPM_status));
				break;
			default:
				send_packet(PACKET_UART_CH_1, NULL, 0);
				break;
		}
	}
	else
		send_packet(PACKET_UART_CH_1, NULL, 0);

}

long convert_to_int(uint8 *message)
{
	long response = 0;
	memcpy(&response, message, sizeof(response));

	return response;
}

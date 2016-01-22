#include "BeerPong.h"

extern volatile long M1_current, M2_current;
extern volatile float M1_dutyCycle, M2_dutyCycle;
extern volatile long M1_RPM_status, M2_RPM_status;

void configureFeedback()
{
	Timer_Config feedbackTimer = &feedback;
	feedbackTimer.frequency = 60;
	feedbackTimer.precision = PRECISE;
	feedbackTimer.enabled = TRUE;
	feedbackTimer.pbclk = PB_CLK;
	feedbackTimer.which_timer = TIMER_2;
	initialize_Timer(feedbackTimer);

}

void feedback()
{
	char packets[5];

	ADC_Node node1;
	node1.device_id = M1_READ_CURRENT;
	node1.channel = 0b1;
	node1.callback = &processADC;
	read_ADC(node1);

	node1.device_id = M2_READ_CURRENT;
	node1.channel = 0b10;
	read_ADC(node1);

	//Send our current RPMs up to the computer
	packets[0] = M1_READ_RPM;
	memcpy(&(packets[1]), &M1_RPM_status, sizeof(M1_RPM_status));
	send_packet(PACKET_UART_CH_1, packets, sizeof(packets));

	packets[0] = M2_READ_RPM;
	memcpy(&(packets[1]), &M2_RPM_status, sizeof(M2_RPM_status));
	send_packet(PACKET_UART_CH_1, packets, sizeof(packets));

	//send our current current to the computer
	packets[0] = M1_READ_CURRENT;
	memcpy(&(packets[1]), &M1_current, sizeof(M1_current));
	send_packet(PACKET_UART_CH_1, packets, 3);

	packets[0] = M2_READ_CURRENT;
	memcpy(&(packets[1], &M2_current, sizeof(M2_current));
	send_packet(PACKET_UART_CH_1, packets, 3);

	//Send our current duty cycle to the computer
	packets[0] = M1_READ_DUTYCYCLE;
	memcpy(&(packets[1], &M1_dutyCycle, sizeof(M1_dutyCycle));
	send_packet(PACKET_UART_CH_1, packets, sizeof(packets));
	
	packets[0] = M2_READ_DUTYCYCLE;
	memcpy(&(packets[1], &M2_dutyCycle, sizeof(M1_dutyCycle));
	send_packet(PACKET_UART_CH_1, packets, sizeof(packets));
}

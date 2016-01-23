#include "BeerPong.h"

extern volatile long M1_current, M2_current;
extern volatile float M1_dutyCycle, M2_dutyCycle;
extern volatile long M1_RPM_status, M2_RPM_status;

void configureFeedback_Timer()
{
	Timer_Config feedbackTimer =  {0};
	feedbackTimer.callback = &feedback;
	feedbackTimer.frequency = 60;
	feedbackTimer.precision = PRECISE;
	feedbackTimer.enabled = TRUE;
	feedbackTimer.pbclk = PB_CLK;
	feedbackTimer.which_timer = TIMER_2;
	initialize_Timer(feedbackTimer);

}

void feedback()
{
	uint8_t packets[5];

	long tmp;

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
	tmp = M1_RPM_status;
	memcpy(&(packets[1]), &tmp, sizeof(M1_RPM_status));
	send_packet(PACKET_UART_CH_1, packets, sizeof(packets));

	packets[0] = M2_READ_RPM;
	tmp = M2_RPM_status;
	memcpy(&(packets[1]), &tmp, sizeof(M2_RPM_status));
	send_packet(PACKET_UART_CH_1, packets, sizeof(packets));

	//send our current current to the computer
	packets[0] = M1_READ_CURRENT;
	tmp = M1_current;
	memcpy(&(packets[1]), &tmp, sizeof(M1_current));
	send_packet(PACKET_UART_CH_1, packets, 3);

	packets[0] = M2_READ_CURRENT;
	tmp = M2_current;
	memcpy(&(packets[1]), &tmp, sizeof(M2_current));
	send_packet(PACKET_UART_CH_1, packets, 3);

	//Send our current duty cycle to the computer
	packets[0] = M1_READ_DUTYCYCLE;
	tmp = M1_dutyCycle;
	memcpy(&(packets[1]), &tmp, sizeof(M1_dutyCycle));
	send_packet(PACKET_UART_CH_1, packets, sizeof(packets));
	
	packets[0] = M2_READ_DUTYCYCLE;
	tmp = M2_dutyCycle;
	memcpy(&(packets[1]), &tmp, sizeof(M1_dutyCycle));
	send_packet(PACKET_UART_CH_1, packets, sizeof(packets));
}


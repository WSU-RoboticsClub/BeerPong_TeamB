#include "BeerPong.h"

extern volatile uint32_t M1_current, M2_current;
extern volatile uint32_t M1_dutyCycle, M2_dutyCycle;
extern volatile uint32_t M1_RPM_status, M2_RPM_status;

void configureFeedback_Timer()
{
	Timer_Config feedbackTimer =  {0};
	feedbackTimer.callback = &feedback;
	feedbackTimer.frequency = 65;
	feedbackTimer.precision = SIMPLE;
	feedbackTimer.enabled = TRUE;
	feedbackTimer.pbclk = PB_CLK;
	feedbackTimer.which_timer = TIMER_2;
	initialize_Timer(feedbackTimer);

}

void feedback()
{
	uint8_t packets[5];

	uint32_t tmp;
	
	ADC_Node node1, node2;

	node1.device_id = M1_STATUS_CURRENT;
	node1.channel = ADC_CH_0;
	node1.callback = &processADC;
	read_ADC(node1);

	node2.device_id = M2_STATUS_CURRENT;
	node2.channel = ADC_CH_1;
	node2.callback = &processADC;
	read_ADC(node2);

	//Send our current RPMs up to the computer
	packets[0] = M1_STATUS_RPM;
	tmp = M1_RPM_status;
	memcpy(&(packets[1]), &tmp, sizeof(tmp));
	send_packet(PACKET_UART_CH_1, packets, 5);
	
	   packets[0] = M2_STATUS_RPM;
	   tmp = M2_RPM_status;
	   memcpy(&(packets[1]), &tmp, sizeof(M2_RPM_status));
	   send_packet(PACKET_UART_CH_1, packets, sizeof(packets));

	//send our current current to the computer
	packets[0] = M1_STATUS_CURRENT;
	tmp = M1_current;
	memcpy(&(packets[1]), &tmp, sizeof(M1_current));
	send_packet(PACKET_UART_CH_1, packets, 3);

	packets[0] = M2_STATUS_CURRENT;
	tmp = M2_current;
	memcpy(&(packets[1]), &tmp, sizeof(M2_current));
	send_packet(PACKET_UART_CH_1, packets, 3);

	//Send our current duty cycle to the computer
	packets[0] = M1_STATUS_DUTYCYCLE;
	tmp = M1_dutyCycle;
	memcpy(&(packets[1]), &tmp, sizeof(M1_dutyCycle));
	send_packet(PACKET_UART_CH_1, packets, sizeof(packets));

	packets[0] = M2_STATUS_DUTYCYCLE;
	tmp = M2_dutyCycle;
	memcpy(&(packets[1]), &tmp, sizeof(M1_dutyCycle));
	send_packet(PACKET_UART_CH_1, packets, sizeof(packets));
}


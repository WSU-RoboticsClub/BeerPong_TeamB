#include "BeerPong.h"

uint8 work_buffer[256];
uint8 results_buffer[256];

void configureADC()
{
	ADC_Config adc = {0};
	adc.channels = 0b11;
	adc.work_buffer_ptr = work_buffer;
	adc.work_buffer_size = sizeof(work_buffer);
	adc.result_buffer_ptr = results_buffer;
	adc.result_buffer_size = sizeof(results_buffer);
	adc.callback = NULL;
	initialize_ADC(adc);
}

void processADC(ADC_Node node)
{
	char packet[3];
	switch (node.device_id)
	{
		case M1_READ_CURRENT:
			M1_current = node.data;
			break;
		case M2_READ_CURRENT:
			M2_current = node.data;
			break;
	}
}

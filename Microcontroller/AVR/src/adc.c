#include "BeerPong.h"

uint8 work_buffer[256];
uint8 results_buffer[256];

extern volatile int M1_current, M2_current;

void configureADC()
{
	ADC_Config adc = {0};
	adc.channels = 1<<ADC_CH_0 | 1<<ADC_CH_1;
	adc.work_buffer_ptr = work_buffer;
	adc.work_buffer_size = sizeof(work_buffer);
	adc.result_buffer_ptr = results_buffer;
	adc.result_buffer_size = sizeof(results_buffer);
	adc.callback = NULL;
	initialize_ADC(adc);
}

void processADC(ADC_Node node)
{
	switch (node.device_id)
	{
		case M1_STATUS_CURRENT:
			M1_current = node.data;
			break;
		case M2_STATUS_CURRENT:
			M2_current = node.data;
			break;
	}
}

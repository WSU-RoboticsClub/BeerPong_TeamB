#include "BeerPong.h"

	

    //Motor Variables
    
/*************************************************************************
 Main Function
 ************************************************************************/
int main(void) {

	configureMotors(); //Initialize the motors to run the flywheels
    establishUART(); //Initialize UART
	configureFeedback();

	configureADC();    
    enable_Interrupts(); //Global interrupt enable. Do this last!
    
    
    while (1) {
		bg_process_ADC();
		bg_process_packetizer(PACKET_UART_CH_1); //process received messagesi
    }
}

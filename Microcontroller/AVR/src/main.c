#include "BeerPong.h"

	
	//Serial Variables	
    uint8_t uart_rx_buffer[BUFFER_SIZE], uart_tx_buffer [BUFFER_SIZE]; //Serial buffers

	char update = 0;
    //Motor Variables
    volatile long M1_RPM_goal = 0, 
                 M2_RPM_goal = 0,
                 M1_RPM_status = 0, 
                 M2_RPM_status = 0;			 
    
/*************************************************************************
 Main Function
 ************************************************************************/
int main(void) {

	configureMotors(); //Initialize the motors to run the flywheels
    establishUART(); //Initialize UART
    
    enable_Interrupts(); //Global interrupt enable. Do this last!
    
    
    while (1) {
        bg_process_packetizer(PACKET_UART_CH_1); //process received messagesi
		if (update) updatePIDControllers();
    }
}

#include "BeerPong.h"

	
	//Serial Variables	
    char uart_rx_buffer[BUFFER_SIZE], uart_tx_buffer [BUFFER_SIZE]; //Serial buffers
	volatile int sync = 0; //Our sync status.
	volatile long serial_timeout = 0; //Timer1 overflows since last serial message. When >= 980, we have no serail for 1 second, so lose sync
	const char KEY = 'a'; //Key for synchronization. We expect to get this echoed for sync
    

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
        if (!sync)
            acquireSynchronization();
        bg_process_packetizer(PACKET_UART_CH_1); //process received messages
    }
}

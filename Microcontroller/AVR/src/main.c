#include "beerpong.h"

    char uart_rx_buffer[BUFFER_SIZE], uart_tx_buffer [BUFFER_SIZE];
    volatile int sync = 0;
    const char KEY = 'a';
    
    //Motor Variables
    volatile long M1_RPM_goal = 0, 
                 M2_RPM_goal = 0,
                 M1_RPM_status = 0, 
                 M2_RPM_status = 0;
				 
	volatile long M1_MAGNET_CNT = 0,
				 M2_MAGNET_CNT = 0;
    
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

void configureSystemTimer() //The system timer handles all feedback signalling
{
    Timer_Config systemTimer = {0};
    systemTimer.callback = &updateStatus;
    systemTimer.enabled = TRUE;
    systemTimer.frequency = REFRESH_FREQUENCY; //Refresh feedback info at 50Hz
    systemTimer.pbclk = PB_CLK;
    systemTimer.which_timer = TIMER_2;
    initialize_Timer(systemTimer);
    
    //Timeout timer to reacquire sync
    systemTimer.callback = &resync;
    systemTimer.frequency = 1;
    systemTimer.which_timer = TIMER_1;
    initialize_Timer(systemTimer);
}

void updateStatus()
{
    //Update the RPM of motors and position information based upon feedback values
	
	//RPM = rotations/min = (rotations/60) / second = (rotations/60)/REFRESH_FREQUENCY / REFRESH_FREQ
	//RPM = rotations per refresh * REFRESH_FREQUENCY * 60 
	M1_RPM_status = (M1_MAGNET_CNT/(double)4) * REFRESH_FREQUENCY * 60;
	M1_MAGNET_CNT = 0;
    
    //Reset all counts for feedback
}

void resync()
{
    sync = 0;
}
#include "beerpong.h"
#include "sublibinal_config.h"

    char uart_rx_buffer[BUFFER_SIZE], uart_tx_buffer [BUFFER_SIZE];
    volatile int sync = 0;
    const char KEY = 'a';
    
    //Motor Variables
    volatile int M1_RPM_goal = 0, 
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

void configureSystemTimer() //The system timer handles all feedback signalling
{
    Timer_Config systemTimer = {0};
    systemTimer.callback = &updateStatus;
    systemTimer.enabled = TRUE;
    systemTimer.frequency = REFRESH_FREQUENCY; //Refresh feedback info at 50Hz
    systemTimer.pbclk = PB_CLK;
    systemTimer.which_timer = Timer_1;
    initialize_Timer(systemTimer);
    
    //Timeout timer to reacquire sync
    systemTimer.callback = &resync;
    systemTimer.frequency = 1;
    systemTimer.which_timer = Timer_4;
    initialize_Timer(systemTimer);
}

void updateStatus()
{
    //Update the RPM of motors and position information based upon feedback values
    
    //Reset all counts for feedback
}

void resync()
{
    sync = 0;
}
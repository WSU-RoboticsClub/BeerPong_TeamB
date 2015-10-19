
/********************************************************
 *   File Name: main.c
 *
 *   Description:
 *              Main file
 *
 *
 *********************************************************/

/*************************************************************************
 System Includes
 ************************************************************************/
#include "sublibinal.h"
#include "sublibinal_config.h"

/*************************************************************************
 Processor Configuration
 ************************************************************************/



//forward declarations
void timer_callback(void);

/*************************************************************************
 Main Function
 ************************************************************************/
int main(void) {

    //structures for configuring peripherals
    Timer_Config timer_config = {0};

    //setup peripherals
    timer_config.frequency = 1; //Have the timer trigger at a rate of 1Hz
    timer_config.pbclk = 15000000; //The peripheral bus clock is configured to operate at 15MHz
    timer_config.which_timer = Timer_1; //Use Timer 1
    timer_config.callback = &timer_callback; //Hand a callback function for the ISR
    timer_config.enabled = 1; //Enable the Timer
    initialize_Timer(timer_config); //Initialize the timer module
 
    //Global interrupt enable. Do this last!
    INTEnableSystemMultiVectoredInt();
    asm volatile ("ei"); //reenable interrupts

    while (1) {
        //background tasks here, if necessary
    }

    return 0;
}

void timer_callback(void)
{
    
}

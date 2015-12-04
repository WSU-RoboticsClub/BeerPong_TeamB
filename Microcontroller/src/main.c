
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
void timer1_callback(void);

//Global Vars
uint8 speed = 1;
uint8 direction = 0;
PWM_Config pwm1_config = {0}, pwm2_config = {0};

/*************************************************************************
 Main Function
 ************************************************************************/
int main(void) {

    //structures for configuring peripherals
    Timer_Config timer1_config = {0}, timer2_config = {0}, timer3_config = {0};
    //setup Timer 1
    timer1_config.frequency = 1; //Have the timer trigger at a rate of 1Hz
    timer1_config.pbclk = PB_CLK; //The peripheral bus clock is configured to operate at 15MHz
    timer1_config.which_timer = Timer_1; //Use Timer 1
    timer1_config.callback = &timer1_callback; //Hand a callback function for the ISR
    timer1_config.enabled = 1; //Enable the Timer
    initialize_Timer(timer1_config); //Initialize the timer module
 
    //Setup Timer 2
    timer2_config.frequency = 500; //Change later
    timer2_config.pbclk = PB_CLK;
    timer2_config.which_timer = Timer_2;
    timer2_config.callback = NULL;
    timer2_config.enabled = 1;
    initialize_Timer(timer2_config);
    
    //Setup Timer 3
    timer3_config.frequency = 500; //Change later
    timer3_config.pbclk = PB_CLK;
    timer3_config.which_timer = Timer_3;
    timer3_config.callback = NULL;
    timer3_config.enabled = 1;
    initialize_Timer(timer3_config);
    
    //Setup PWM 1
    pwm1_config.timer = timer2_config; //Use Timer 2
    pwm1_config.channel = PWM_CH_1;
    pwm1_config.pin = Pin_RPB3; //Use Pin 7
    pwm1_config.dutyCycle = 0; //Initialize with 0% duty cycle
    pwm1_config.enable = 0; //Initially Disable the output
    initialize_PWM(pwm1_config);
    
    //Setup PWM 2
    pwm2_config.timer = timer3_config; //Use Timer 3
    pwm2_config.channel = PWM_CH_2;
    pwm2_config.pin = Pin_RPB5; //Use Pin 14
    pwm2_config.dutyCycle = 0; //Initialize with 0% duty cycle
    pwm2_config.enable = 0; //Initially Disable the output
    initialize_PWM(pwm2_config);
    
    //Setup the direction pin outputs 
    //M1
    //Use RB1 (pin 5) and RB2 (pin 6) & Disable AN3 and AN4
    TRISBbits.TRISB1 = 0; //Enable RB1 as output
    ANSELBbits.ANSB1 = 0; //Disable AN3
    TRISBbits.TRISB2 = 0; //Enable RB2 as output
    ANSELBbits.ANSB2 = 0; //Disable AN4
    //M2
    //Use RB7 (pin 16) and RB8 (pin 17)
    TRISBbits.TRISB7 = 0; //Enable RB7 as output
    TRISBbits.TRISB8 = 0; //Enable RB8 as output
    
    //Global interrupt enable. Do this last!
    enable_Interrupts();

    while (1) {
        //background tasks here, if necessary
    }

    return 0;
}

void timer1_callback(void)
{
    //Every Second change the speed and/or direction
    switch (speed)
    {
        case 1:
            update_PWM(pwm1_config, 0.25);
            speed++;
            break;
        case 2:
            update_PWM(pwm1_config, 0.5);
            speed++;
            break;
        case 3:
            update_PWM(pwm1_config, 0.75);
            speed++;
            break;
        default:
            //Switch Direction
            if (direction == 0)
            {
                disable_PWM(pwm1_config);
                LATBbits.LATB1 = 1;
                LATBbits.LATB2 = 0;
                update_PWM(pwm1_config, 0);
                enable_PWM(pwm1_config);
                direction = 1;
            }
            else
            {
                disable_PWM(pwm1_config);
                LATBbits.LATB1 = 0;
                LATBbits.LATB2 = 1;
                update_PWM(pwm1_config, 0);
                enable_PWM(pwm1_config);
                direction = 0;
            }
            speed = 1;
            break;
    }
}
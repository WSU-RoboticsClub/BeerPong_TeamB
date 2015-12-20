#include "beerpong.h"

//The motors will utilize Timers 2 and 3 on pins B4 and B11 respectively
//They also use B5 and B7 as direction pins for M1
//And B8 and B9 as direction pins for M2
void configureMotors()
{
    Timer_Config timerOne = {0}, timerTwo = {0};
    PWM_Config motorOne = {0}, motorTwo = {0};
    
    timerOne.callback = NULL;
    timerOne.enabled = TRUE;
    timerOne.frequency = 500;
    timerOne.pbclk = PB_CLK;
    timerOne.which_timer = Timer_2;
    initialize_Timer(timerOne);
    
    timerTwo.callback = NULL;
    timerTwo.enabled = TRUE;
    timerTwo.frequency = 500;
    timerTwo.pbclk = PB_CLK;
    timerTwo.which_timer = Timer_3;
    initialize_Timer(timerTwo);
    
    motorOne.channel = PWM_CH_1;
    motorOne.dutyCycle = .5;
    motorOne.enable = TRUE;
    motorOne.pin = Pin_RPB4;
    motorOne.timer = timerOne;
    initialize_PWM(motorOne);
    
    motorTwo.channel = PWM_CH_2;
    motorTwo.dutyCycle = .5;
    motorTwo.enable = TRUE;
    motorTwo.pin = Pin_RPB11;
    motorTwo.timer = timerTwo;
    initialize_PWM(motorTwo);
    
    //Setup the direction pin outputs 
    //M1
    //Use RB5 and RB7
    ODCBbits.ODCB5 = 1;
    ODCBbits.ODCB7 = 1;
    TRISBbits.TRISB5 = 0; //output
    TRISBbits.TRISB7 = 0; //output
    
    LATBbits.LATB5 = 0;
    LATBbits.LATB7 = 1; //Dir = backwards
        
    //M2
    ODCBbits.ODCB8 = 1;
    ODCBbits.ODCB9 = 1;
    
    //Use RB8 and RB9
    
    TRISBbits.TRISB8 = 0; //Enable RB7 as output
    TRISBbits.TRISB9 = 0; //Enable RB8 as output
    
    LATBbits.LATB8 = 0;
    LATBbits.LATB9 = 1; //Dir  = backwards
}

//This function configures feedback for the hall effect sensors 
//The purpose of feedback is so we can see our motors rotational speed
void configureFeedback()
{

}
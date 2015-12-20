#include "beerpong.h"

/*************************************************************************
 Main Function
 ************************************************************************/
int main(void) {
    
    configureMotors(); //Initialize the motors to run the flywheels
    
    
    enable_Interrupts(); //Global interrupt enable. Do this last!
    
    //Next, Acquire Sync with the main computer
    acquireSynchronization();
    
    while (1) {
        bg_process_packetizer(PACKET_UART_CH_1); //process received messages
    }
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
                LATBbits.LATB5 = 1;
                LATBbits.LATB7 = 0;
                update_PWM(pwm1_config, 0);
                enable_PWM(pwm1_config);
                direction = 1;
            }
            else
            {
                disable_PWM(pwm1_config);
                LATBbits.LATB5 = 0;
                LATBbits.LATB7 = 1;
                update_PWM(pwm1_config, 0);
                enable_PWM(pwm1_config);
                direction = 0;
            }
            speed = 1;
            break;
    }
}
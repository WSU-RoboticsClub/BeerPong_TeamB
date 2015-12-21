#include "beerpong.h"

extern char uart_rx_buffer[BUFFER_SIZE], uart_tx_buffer [BUFFER_SIZE];
extern volatile int sync;
extern const char KEY;
extern volatile long M1_MAGNET_CNT,
					M2_MAGNET_CNT;

//Motor Variables
extern volatile long M1_RPM_goal,
M2_RPM_goal,
M1_RPM_status,
M2_RPM_status;
volatile int timeout;

//The motors will utilize Timers 2 and 3 on pins B4 and B11 respectively
//They also use B5 and B7 as direction pins for M1
//And B8 and B9 as direction pins for M2
void configureMotors()
{
	Timer_Config timerOne = {0}, timerTwo = {0};
	PWM_Config motorOne = {0}, motorTwo = {0};
	
	timerOne.callback = NULL;
	timerOne.enabled = TRUE;
	timerOne.frequency = 980;
	timerOne.pbclk = PB_CLK;
	timerOne.which_timer = TIMER_0;
	initialize_Timer(timerOne);
	
	//PWM on PD6
	motorOne.channel = PWM_CH_1A_SIMPLE;
	motorOne.dutyCycle = .5;
	motorOne.enable = TRUE;
	initialize_PWM(motorOne);
	
	//PWM on PD5
	motorTwo.channel = PWM_CH_1B_SIMPLE;
	motorTwo.dutyCycle = .5;
	motorTwo.enable = TRUE;
	initialize_PWM(motorTwo);
	
	//Set the output dir pins
	//B0 and B1 for one
	DDRB |= (1<<1) | (1<<0);
	PORTB |= (1<<0);
	PORTB &= ~(1<<1);
	
	//B2 and B3 for two
	DDRB |= (1<<2) | (1<<3);
	PORTB |= (1<<2);
	PORTB &= ~(1<<3);
	
}

void interrupt_m1()
{
	M1_MAGNET_CNT++;
}

//This function configures feedback for the hall effect sensors
//The purpose of feedback is so we can see our motors rotational speed
void configureFeedback()
{
	Interrupt_Config intcon = {0};
		intcon.callback = &interrupt_m1;
		intcon.enable = TRUE;
		intcon.extInt = INT_0;
		intcon.polarity = falling;
		intcon.resistor = pullup;
		initialize_Interrupt(intcon);
}
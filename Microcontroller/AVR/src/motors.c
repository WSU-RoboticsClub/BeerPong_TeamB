#include "BeerPong.h"

//Motor Variables
volatile long M1_RPM_status = 0, 
		 M2_RPM_status = 0;			

volatile float M1_dutyCycle,
		 M2_dutyCycle;

volatile int M1_current,
		 M2_current;

volatile long timerOne_overflow_cnt_m1 = 0; //Overflow count since last RPM calculation 
volatile long timerOne_overflow_cnt_m2 = 0; //Overflow count since last RPM calculation 

volatile long lastRead_m1 = 0;//Internal
volatile long lastRead_m2 = 0;//Internal

//Variables

//The motors will utilize Timer 1
void configureMotors()
{
	Timer_Config timerOne = {0};
	PWM_Config motorOne = {0}, motorTwo = {0};

	timerOne.precision = SIMPLE;	
	timerOne.enabled = TRUE;
	timerOne.callback = NULL;
	timerOne.frequency = 980;
	timerOne.pbclk = PB_CLK;
	timerOne.which_timer = TIMER_0;
	initialize_Timer(timerOne);

	//PWM on PD6
	motorOne.channel = PWM_CH_1A_SIMPLE;
	motorOne.dutyCycle = 0;
	motorOne.enable = TRUE;
	initialize_PWM(motorOne);

	//PWM on PD5
	motorTwo.channel = PWM_CH_1B_SIMPLE;
	motorTwo.dutyCycle = 0;
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

	configureFeedback();

}

//This function configures feedback for the hall effect sensors
//The purpose of feedback is so we can see our motors rotational speed
void configureFeedback()
{
	//Configure for motor 1
	Interrupt_Config intcon = {0};
	intcon.callback = &interrupt_m1;
	intcon.enable = TRUE;
	intcon.extInt = INT_0;
	intcon.polarity = falling;
	intcon.resistor = pullup;
	initialize_Interrupt(intcon);

	//Configure for motor 2
	Interrupt_Config intcon2 = {0};
	intcon2.callback = &interrupt_m2;
	intcon2.enable = TRUE;
	intcon2.extInt = INT_1;
	intcon2.polarity = falling;
	intcon2.resistor = pullup;
	initialize_Interrupt(intcon2);

	Timer_Config feedback_timer = {0};
	feedback_timer.callback = &feedback_tmr_ovf;
	feedback_timer.enabled = TRUE;
	feedback_timer.frequency = 244;
	feedback_timer.precision = SIMPLE;
	feedback_timer.pbclk = PB_CLK;
	feedback_timer.which_timer = TIMER_1;
	initialize_Timer(feedback_timer);

	timerOne_overflow_cnt_m1 = 0;
	timerOne_overflow_cnt_m2 = 0;
	lastRead_m1 = 0;
	lastRead_m2 = 0;
}

//Callback functions
void feedback_tmr_ovf()
{
	//increment overflow count
	timerOne_overflow_cnt_m1++;
	timerOne_overflow_cnt_m2++;

	if (timerOne_overflow_cnt_m1 >= 244)
		M1_RPM_status = 0;
	if (timerOne_overflow_cnt_m2 >= 244)
		M2_RPM_status = 0;

}


void interrupt_m2()
{
	//Determine total timer counts that have occurred since last timeout
	//RPM = 1 Revolution / Time (m)
	//Time (m) = totalCounts * timePerCount (s) / 60 (s/m)
	//RPM = 1 / (totalCounts * timePerCount / 60)
	//totalCounts = (TMR - lastRead) + 255*timerOne_overflow_cnt;
	//timePerCount = 1/(Sysclock / Timer1 divider)
	//Sysclock = 16MHz
	//timer1 divider = 1
	//timePerCount = 1/(16MHz) = 62.5 nanoseconds
	long totalCounts = (TCNT1 - lastRead_m2) + 65535*timerOne_overflow_cnt_m2;
	double totalTime = totalCounts * ((1/(float)16000000)/60);
	M2_RPM_status = ((double)1)/(totalTime*2); //Multiply total time by 2 (We have four magnets, so each interrupt is actually only 1/2 of a rotation)

	lastRead_m2 = TCNT1; //Reset last read 
	timerOne_overflow_cnt_m2 = 0; //Reset overflow count
}

void interrupt_m1()
{
	//Determine total timer counts that have occurred since last timeout
	//RPM = 1 Revolution / Time (m)
	//Time (m) = totalCounts * timePerCount (s) / 60 (s/m)
	//RPM = 1 / (totalCounts * timePerCount / 60)
	//totalCounts = (TMR - lastRead) + 255*timerOne_overflow_cnt;
	//timePerCount = 1/(Sysclock / Timer1 divider)
	//Sysclock = 16MHz
	//timer1 divider = 1
	//timePerCount = 1/(16MHz) = 62.5 nanoseconds
	long totalCounts = (TCNT1 - lastRead_m1) + 65535*timerOne_overflow_cnt_m1;
	double totalTime = totalCounts * ((1/(double)16000000)/60);
	M1_RPM_status = ((double)1)/(totalTime*4); //Multiply total time by 4 (We have four magnets, so each interrupt is actually only 1/4 of a rotation)

	lastRead_m1 = TCNT1; //Reset last read 
	timerOne_overflow_cnt_m1 = 0; //Reset overflow count
}


/*
 * BeerPong.h
 *
 * Created: 12/20/2015 8:42:58 PM
 *  Author: Ryan
 */ 


#ifndef BEERPONG_H_
#define BEERPONG_H_


#ifdef	__cplusplus
extern "C" {
#endif


/* Includes */
#include "sublibinal.h"
#include <string.h>
/* Global Definitions */
#define BUFFER_SIZE 512 // This defines the size of the UART buffers
#define SYNC_COUNT 10 // This defines how many messages are sent to acquire sync
#define REFRESH_FREQUENCY 1 //Rate at which feedback status is updated

//Serial Description Bytes
#define M1_SET_RPM 0x01
#define M2_SET_RPM 0x02
#define M1_READ_RPM 0x11
#define M2_READ_RPM 0x12
#define M1_READ_GOAL 0x31
#define M2_READ_GOAL 0x32

#define PB_CLK 16000000


/* Function Prototypes */
//main
void updateStatus();

//Motors
void configureMotors(); //Configuration and instantiation of the flywheel motors
void motor_callback(); //Callback for Timer_0 overflow	
void configureFeedback(); //configure feedback from the motors through hall effect sensors
void interrupt_m1(); //Callback function for feedback for motor 1
void interrupt_m2(); //Callback function for feedback for motor 2
void feedback_tmr_ovf();



//Serial
void establishUART(); //Create our serial interface with packetizer enabled
void packetizer_callback(uint8 *message, uint8 size); //Callback for the packetizer receive
void configureFeedback(); //Configure the feedback for the motors

//ADC
void configureADC();
void processADC(ADC_Node node);


#ifdef	__cplusplus
}
#endif



#endif /* BEERPONG_H_ */

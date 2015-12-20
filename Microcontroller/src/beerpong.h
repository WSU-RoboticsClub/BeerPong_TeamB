

#ifndef BEER_PONG_H
#define BEER_PONG_H

/* Includes */
#include "sublibinal.h"
#include "sublibinal_config.h"

/* Global Definitions */
#define BUFFER_SIZE 256 // This defines the size of the UART buffers
#define SYNC_COUNT 10 // This defines how many messages are sent to acquire sync

    //Serial Description Bytes
    #define M1_SET_RPM 0x01
    #define M2_SET_RPM 0x02
    #define M1_READ_RPM 0x11
    #define M2_READ_RPM 0x12

/* Global Variables */

    //UART Variables
    char uart_rx_buffer[BUFFER_SIZE], uart_tx_buffer [BUFFER_SIZE];
    volatile int sync = 0;
    const char KEY = 'a';
    
    //Motor Variables
    volatile int M1_RPM_goal = 0, 
                 M2_RPM_goal = 0,
                 M1_RPM_status = 0, 
                 M2_RPM_status = 0;

/* Function Prototypes */
    //main
    void timer1_callback(void);

    //Motors
    void configureMotors(); //Configuration and instantiation of the flywheel motors
    
    //Serial
    void establishUART(); //Create our serial interface with packetizer enabled
    void acquireSynchronization(); //Acquire synchronization with the main computer
    void packetizer_callback(uint8 *message, uint8 size); //Callback for the packetizer receive



#endif
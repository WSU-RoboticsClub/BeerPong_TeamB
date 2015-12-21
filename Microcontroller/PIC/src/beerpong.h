

#ifndef BEER_PONG_H
#define BEER_PONG_H

#ifdef	__cplusplus
extern "C" {
#endif


/* Includes */
#include "sublibinal.h"

/* Global Definitions */
#define BUFFER_SIZE 256 // This defines the size of the UART buffers
#define SYNC_COUNT 10 // This defines how many messages are sent to acquire sync
#define REFRESH_FREQUENCY 100 //Rate at which feedback status is updated

    //Serial Description Bytes
    #define M1_SET_RPM 0x01
    #define M2_SET_RPM 0x02
    #define M1_READ_RPM 0x11
    #define M2_READ_RPM 0x12

/* Global Variables */

    //UART Variables


/* Function Prototypes */
    //main
    void configureSystemTimer(); //Configure the main system timer for calculating state from feedback
    void updateStatus();
    void resync();

    //Motors
    void configureMotors(); //Configuration and instantiation of the flywheel motors
    
    //Serial
    void establishUART(); //Create our serial interface with packetizer enabled
    void acquireSynchronization(); //Acquire synchronization with the main computer
    void packetizer_callback(uint8 *message, uint8 size); //Callback for the packetizer receive


#ifdef	__cplusplus
}
#endif

#endif

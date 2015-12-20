#ifndef __PACKETIZER_H__
#define __PACKETIZER_H__

//#include <cstdint>
#include "Serial.hpp"
#include <iostream>

using std::cout;

class Packetizer
{
    public:
        Packetizer(const char *port_name, uint8_t control_byte);
        ~Packetizer();
        int get(uint8_t *buf);
        void flush();
        int send(uint8_t *buf, uint8_t num);
        void get_lock(void);
        int getBytesAvailable();

    private:

        Serial *serial;
        char control_byte;

        static const int MAX_PACKET_SIZE = 255;
};

#endif

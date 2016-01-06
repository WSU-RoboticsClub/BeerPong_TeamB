
#include "Serial.hpp"

Serial::Serial(const char *port_name, int baud_rate)
{
    this->port_fd = open(port_name, O_RDWR | O_NOCTTY);
    if (this->port_fd < 0)
    {
        cout << "could not open port: " << port_name << endl;
    }

    this->configure(baud_rate);
}

Serial::~Serial()
{
    close(this->port_fd);
}


int Serial::swrite(uint8_t *buf, int num)
{
    int i;
    int sent = 0;

    while(sent < num)
    {
        i = write(this->port_fd, buf, num);
        if (i < 0)
        {
            cout << "serial write error" << endl;
        }
        else
        {
            sent += i;
        }
    }

    return sent;
}

int Serial::sread(uint8_t *buf, int num)
{
    int i;

        i = read(this->port_fd, buf, num);
        if(i != num)
        {
            cout << "Serial Read Error";
        }

    return i;
}

void Serial::configure(int baudRate)
{
    struct termios portConfig = {0}; //initialize our termios structure
    int portHandle = this->port_fd;

    if (tcgetattr(portHandle, &portConfig) != 0) {
        printf("Get Attributes failed.\n Error: %d", errno);
        //return -1;
    }

    //manually configure the port flags
    portConfig.c_oflag = 0; //do not filter the output of the serial port
    portConfig.c_lflag = 0; //Do not use signalling characters

    portConfig.c_cflag |= (portConfig.c_cflag & ~CSIZE) | CS8; //Set 8 bit
    portConfig.c_cflag |= CREAD | CLOCAL; //8 bit, enable receiver, ignore modem controls
    portConfig.c_cflag &= ~(PARENB | PARODD); //Disable parity
    portConfig.c_cflag &= ~(CSTOPB); //Set 1 stop bit
    portConfig.c_cflag &= ~(CRTSCTS); //Disable RTS CTS flow control

    portConfig.c_iflag |= IGNBRK | IGNPAR | IGNCR; //ignore break, parity errors, and carriage returns
    portConfig.c_iflag &= ~(IXON | IXOFF | IXANY);

    cfsetospeed(&portConfig, baudRate);
    cfsetispeed(&portConfig, baudRate);

    portConfig.c_cc[VMIN] = 255; //the port will not return until timeout occurs or bytes requested are red OR 255 (whichever is less)
    portConfig.c_cc[VTIME] = 5; //the port has .5 second timeout after first byte

    if (tcsetattr(portHandle, TCSANOW,  &portConfig) != 0)
    {
        printf("Failed to set port attributes. Error: %d\n", errno);
        //return -1;
    }

    //INFO("done!");
}

void Serial::flush()
{
    tcflush(port_fd, TCIOFLUSH);
}

int Serial::queryBufferSize()
{
    int available;
    ioctl(port_fd, FIONREAD, &available);
    return available;
}


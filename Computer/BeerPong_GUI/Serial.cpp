
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

void Serial::configure(int baud_rate)
{
    struct termios options = {0};
    int fd = this->port_fd;

    //INFO("configuring port");

    if (tcgetattr(this->port_fd, &options) != 0)
    {
        cout << "Failed to get attributes." << endl;
    }

    options.c_iflag = 0; //no input handling
    options.c_oflag = 0; //no output mapping
    options.c_cflag = (options.c_cflag & ~CSIZE) | CS8; //utilize 8 bit works and clear the current word setting to be overwritten (masked)
    options.c_cflag |= CLOCAL | CREAD; //disable modem controls and enable the receiver

    cfmakeraw(&options);

    cfsetispeed(&options, baud_rate);
    cfsetospeed(&options, baud_rate);

    //set the timeout to be 0 and the minimum characters to 255.
    //This will make the port never time out unless 255 or specified characters are read on the port
    //this setup will cause the program to hang if no data is being received on the port
    options.c_cc[VMIN] = 255;
    options.c_cc[VTIME] = 5;

    if (tcsetattr(fd, TCSANOW, &options) != 0)
    {
        cout << "Failed to set the serial port options.";
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


#include "portreader.hpp"
#include "mainwindow.h"



PortReader::PortReader(MainWindow *parent, string portName, int baudRate, char control, int framerate)
{
    connect(parent, SIGNAL(sendCommand(QString)), this, SLOT(send(QString)));

    port = new Packetizer(portName, control, baudRate);
    this->framerate = framerate;
    running = false;
}

PortReader::~PortReader()
{
    delete port;
}

void PortReader::send(QString command)
{
    char *message = new char[command.size()];
    for (int i = 0; i < command.size(); i++)
    {
        message[i] = command.at(i).toLatin1();
    }

    if (running)
        port->writePacket(message, command.size());

    delete message;
}

bool PortReader::Start()
{
    if (port->open())
    {
        this->running = true;
        start(NormalPriority);
        return true;
    }
    else
    {
        running = false;
        return false;
    }

}

bool PortReader::Stop()
{
    running = false;
    wait();
    return true;
}

void PortReader::run()
{
    while (running)
    {
        int length;
        //Send our data query commands down to the device
        char command = MOTOR1_RPMS;
        port->writePacket(&command, 1);
        command = MOTOR2_RPMS;
        port->writePacket(&command, 1);
        command = MOTOR1_GOAL;
        port->writePacket(&command, 1);
        command = MOTOR2_GOAL;
        port->writePacket(&command, 1);

        //Continually attempt to read from the serial port until it's empty and emit the signal for the processed data
        char buffer[256];
        int ret = 0;
        while (ret >= 0)
        {
            ret = port->readPacket(buffer); //ret is negative when a packet is unsuccessfully read
            if (ret >= 0)
            {
                buffer[ret] = '\n';
                length = ret;
            }
            else
            {
                buffer[0] = '\n';
                length = 0;
            }
            QString data = QString::fromLatin1(buffer, length);
            emit this->processedPacket(data);

        }

        msleep(1000/framerate);
    }
}

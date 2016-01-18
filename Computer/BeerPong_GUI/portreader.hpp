#ifndef PORTREADER_H
#define PORTREADER_H

#include <QObject>
#include <QThread>
#include "include/Packetizer.hpp"
#include "mainwindow.h"
#include <string.h>

class PortReader : public QThread
{
    Q_OBJECT

public:
    PortReader(MainWindow *parent = 0, string portName = "/dev/ttyUSB0", int baudRate = B115200, char control = '!', int framerate = 30);

    ~PortReader();

    bool Start();
    void run();

    bool Stop();

private slots:
    void send(QString command);

signals:
    void processedPacket(QString packet);

private:
    Packetizer *port;
    bool running;
    int framerate;

};

#endif // PORTREADER_H

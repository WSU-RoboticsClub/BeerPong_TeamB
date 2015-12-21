#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Beer Pong Robot GUI - Alpha v0.1");
    refresh = new QTimer();
    connect(refresh, SIGNAL(timeout()), this, SLOT(refresh_gui()));
    reset = new QTimer();
    connect(reset, SIGNAL(timeout()), this, SLOT(reset_gui()));
    port = new Packetizer("/dev/ttyUSB0", '!');
    disabled = new QPalette();
    disabled->setColor(QPalette::Base, QColor(235,235,235));
    ui->disp_rpm_m1->setPalette(*disabled);
    ui->disp_rpm_m2->setPalette(*disabled);
}

MainWindow::~MainWindow()
{
    delete port;
    delete disabled;
    delete reset;
    delete refresh;
    delete ui;
}

void MainWindow::on_button_getsync_clicked()
{
    unsigned char buffer[20];
    int size = -1;
    //Attempt to get sync on the UART channel
    while (size == -1)
        size = port->get(buffer);

    //Now, we have gotten a packet. Retransmit it 10 times so that the microcontroller can have sync as well
    for (int i = 0; i < 10; i++)
        port->send(buffer, size);


    refresh->start(10);
    ui->button_getsync->setEnabled(false);
    ui->button_getsync->setVisible(false);
}

void MainWindow::refresh_gui()
{
    unsigned char command = 0x11;
    unsigned char buffer[10];
    int available = 0;
    int size = 0;

    //flush the buffer
    port->flush();

    //Query the port for status information
    port->send(&command, sizeof(command));

    //wait until there is enough data to be read
    while (available < 6)
    {
        available = port->getBytesAvailable();

    }

    //Read the status
    size = port->get(buffer);

    //Convert the result
    int rpm = convert(buffer);

    //Set the text on the GUI
    this->ui->disp_rpm_m1->setText(QString::number(rpm));


    //Query motor 2
    command = 0x12;

    //Query the port for status information
    port->send(&command, 1);

    //wait until there is enough data to be read
    while (port->getBytesAvailable() < 6);

    //Read the status
    size = port->get(buffer);

    //Convert the result
    rpm = convert(buffer);

    //Set the text on the GUI
    this->ui->disp_rpm_m2->setText(QString::number(rpm));

}
void MainWindow::on_button_set_targets_clicked()
{
    //Form our messages
    unsigned char message[5];
    int rpm;

    rpm = this->ui->spinBox_target_m1->text().toInt();
    message[0] = 0x01;
    memcpy(&(message[1]), &rpm, 4);

    //Send messages
    port->send(message, 5);


    rpm = this->ui->spinBox_target_m2->text().toInt();
    message[0] = 0x02;
    memcpy(&(message[1]), &rpm, 4);

    //Send messages
    port->send(message, 5);
}

int convert(unsigned char *buf)
{
    int response = 0, i = 0;

    memcpy(&response, buf, 4);

    return response;
}

void MainWindow::on_button_reset_clicked()
{
    refresh->stop();
    reset->start(300); //wait .3 seconds for the microcontroller to lose sync
}


void MainWindow::reset_gui()
{
    reset->stop();
    port->flush();
    ui->button_getsync->setEnabled(true);
    ui->button_getsync->setVisible(true);

}

void MainWindow::on_button_exit_clicked()
{
    exit(0);
}

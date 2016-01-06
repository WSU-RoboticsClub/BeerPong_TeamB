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


    refresh->start(100);
    ui->button_getsync->setEnabled(false);
    ui->button_getsync->setVisible(false);
}

unsigned int MainWindow::sendQueryCommand(char command)
{
    int available = 0;
    unsigned char buffer[10];
    int size;

    //Query the port for status information
    port->send((uint8_t *)&command, sizeof(command));

    int resends = 0;
    time_t start = clock();
    //wait until there is enough data to be read
    while (available < 6 && resends < 5)
    {
        //repeat command if no responses
        if (((double)(clock() - start))/CLOCKS_PER_SEC >= .01)
        {
            resends++;
            port->send((uint8_t *)&command, sizeof(command));
            start = clock();
        }
        available = port->getBytesAvailable();
    }
    if (resends >= 5)
    {
        this->on_button_getsync_clicked();
    }
    else
    {
        //Read the status
        size = port->get((uint8_t *)buffer);

        //Convert the result
        return convert(buffer);
    }
    return 0;

}

void MainWindow::refresh_gui()
{
    refresh->stop();
    int size = 0;

    //flush the buffer
    port->flush();

    unsigned int rpm = sendQueryCommand(0x11);
    this->ui->disp_rpm_m1->setText(QString::number(rpm));

    rpm = sendQueryCommand(0x12);
    this->ui->disp_rpm_m2->setText(QString::number(rpm));

    unsigned int goal = sendQueryCommand(0x31);
    this->ui->disp_goal_m1->setText(QString::number(goal));

    goal = sendQueryCommand(0x32);
    this->ui->disp_goal_m2->setText(QString::number(goal));
    refresh->start(100);
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

unsigned int convert(unsigned char *buf)
{
    unsigned int response = 0, i = 0;

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

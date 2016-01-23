#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Beer Pong Robot GUI - Alpha v1.0");
    disabled = new QPalette();
    enabled = new QPalette();
    disabled->setColor(QPalette::Base, QColor(235,235,235));
    enabled->setColor(QPalette::Base, QColor(255,255,255));
    ui->disp_rpm_m1->setPalette(*disabled);
    ui->disp_rpm_m2->setPalette(*disabled);

    reader = NULL;

    //Enable the open/close button and setTargets
    ui->button_set_targets->setEnabled(false);
    ui->button_set_targets->setPalette(*disabled);

    ui->button_openClose->setEnabled(false);
    ui->button_openClose->setPalette(*disabled);
    ui->button_openClose->setText("Open");
    updatePorts = new QTimer(this);
    connect(updatePorts, SIGNAL(timeout()), this, SLOT(populatePorts()));

    populatePorts();
    updatePorts->start(3000); //Update every 3 seconds

    this->m1 = new PID_Controller(.01);
    this->m2 = new PID_Controller(.01);

    usePID = false;
    updatePID = new QTimer(this);
    connect(updatePID, SIGNAL(timeout()), this, SLOT(updateControllers()));

    rpm_m1 = 0;
    rpm_m2 = 0;
}

void MainWindow::updateData(QString data)
{
    int convertVal;
    //Parse the data to figure out with data this is
    //-> First byte is the command byte that was sent
    string tmp;
    char arr[4];
    int val;
    char curr[2];
    double current = 0;
    int i;
    if (data.size() > 1)
    {

        switch ((u_int8_t)data.at(0).toLatin1())
        {
        case M1_STATUS_RPM:
            for (i = 0; i < 4; i++)
                arr[i] = data.at(i+1).toLatin1();

            convertVal = convert(arr);
            ui->disp_rpm_m1->setText(QString::number(convertVal));
            break;
        case M2_STATUS_RPM:
            for (i = 0; i < 4; i++)
                arr[i] = data.at(i+1).toLatin1();

            convertVal = convert(arr);
            ui->disp_rpm_m2->setText(QString::number(convertVal));
            break;
        case M1_STATUS_DUTYCYCLE:
            for (i = 0; i < 4; i++)
                arr[i] = data.at(i+1).toLatin1();

            convertVal = convert(arr);
            ui->disp_goal_m1->setText(QString::number(convertVal));
            break;
        case M2_STATUS_DUTYCYCLE:
            for (i = 0; i < 4; i++)
                arr[i] = data.at(i+1).toLatin1();

            convertVal = convert(arr);
            ui->disp_goal_m2->setText(QString::number(convertVal));
            break;
        case M1_STATUS_CURRENT:
            //Get the current value.
            curr[0] = data.at(1).toLatin1();
            curr[1] = data.at(2).toLatin1();
            memcpy(&val, curr, 2);
            current = val/1024.0 * 5 * 2; //Val/1024 is the % of 5V, *5V gives actual voltage, 2 A/V
            ui->text_currentM1->setText(QString::number(current));
            break;
        case M2_STATUS_CURRENT:
            //Get the current value.
            curr[0] = data.at(1).toLatin1();
            curr[1] = data.at(2).toLatin1();
            memcpy(&val, curr, 2);
            current = val/1024.0 * 5 * 2; //Val/1024 is the % of 5V, *5V gives actual voltage, 2 A/V
            ui->text_currentM2->setText(QString::number(current));
            break;
        default:
            cout << "Error. Unrecognized packet." << endl;
            break;
        }
    }
}

#ifdef _WIN32

void MainWindow::populatePorts()
{

}

#elif __linux

void MainWindow::populatePorts()
{

    string original = ui->select_port->currentText().toStdString();
    ui->select_port->clear();
    ui->select_port->addItem("None");
    //Use dirent to query for all available ports
    DIR *directory;
    struct dirent *entry;
    char dir[] = "/dev/";

    if ((directory = opendir(dir)) != NULL)
    {
        while ((entry = readdir(directory)) != NULL)
        {
            if (strncmp(entry->d_name, "ttyUSB", 6) == 0 || strncmp(entry->d_name, "ttyACM", 6) == 0)
            {
                ui->select_port->addItem(QString::fromLatin1(entry->d_name));
                if (QString::fromLatin1(entry->d_name).toStdString() == original)
                    ui->select_port->setCurrentIndex(ui->select_port->count()-1);
            }
        }
    }



}

#endif

MainWindow::~MainWindow()
{
    delete m1;
    delete m2;
    delete updatePID;
    if (reader != NULL) delete reader;
    delete disabled;

    delete enabled;
    delete ui;
}

void MainWindow::on_button_set_targets_clicked()
{
    if (!usePID)
    {
        //Form our messages
        char message[6] = {'\n'};
        int rpm;

        rpm = this->ui->spinBox_target_m1->text().toFloat();
        message[0] = M1_SET_DUTYCYCLE;
        memcpy(&(message[1]), &rpm, 4);
        QString tmp = QString::fromLatin1(message, 5);
        emit sendCommand(tmp);

        rpm = this->ui->spinBox_target_m2->text().toFloat();
        message[0] = M2_SET_DUTYCYCLE;
        memcpy(&(message[1]), &rpm, 4);
        emit sendCommand(QString::fromLatin1(message, 5));
    }
}

unsigned int convert(const char *buf)
{
    unsigned int response = 0;

    memcpy(&response, buf, 4);
    return response;
}

void MainWindow::on_button_exit_clicked()
{
    exit(0);
}

void MainWindow::on_button_openClose_clicked()
{
    if (ui->button_openClose->text() == "Open")
    {
        reader->Start();
        ui->button_openClose->setText("Close");
        ui->select_port->setPalette(*disabled);
        ui->select_port->setEnabled(false);
    }
    else
    {
        reader->Stop();
        ui->button_openClose->setText("Open");
        ui->select_port->setPalette(*enabled);
        ui->select_port->setEnabled(true);
    }
}

void MainWindow::on_select_port_activated(const QString &arg1)
{
    QString port = arg1;
#ifdef __linux
    port = "/dev/" + port;
#endif
    //Delete the current reader if it exists before we make a new one
    if (reader)
    {
        QObject::disconnect(reader, SIGNAL(processedPacket(QString)), this, SLOT(updateData(QString)));
        delete reader;
        reader = NULL;
    }

    if (arg1 != "None")
    {
        //Create and connect our reader
        reader = new PortReader(this, port.toStdString());
        QObject::connect(reader, SIGNAL(processedPacket(QString)), this, SLOT(updateData(QString)));

        //Enable the open/close button and setTargets
        ui->button_set_targets->setEnabled(true);
        ui->button_set_targets->setPalette(*enabled);

        ui->button_openClose->setEnabled(true);
        ui->button_openClose->setPalette(*enabled);
        ui->button_openClose->setText("Open");
    }
}

void MainWindow::on_radioButton_toggled(bool checked)
{
    if (checked)
        usePID = true;
}


void MainWindow::on_radioButton_2_toggled(bool checked)
{
    if (checked)
        usePID = false;
}

void MainWindow::updateControllers()
{
    if (usePID)
    {
        float dutyCycle_m1 = ui->disp_rpm_m1->document()->toPlainText().toFloat();
        float dutyCycle_m2 = ui->disp_rpm_m2->document()->toPlainText().toFloat();
        int m1_rpm = ui->disp_rpm_m1->document()->toPlainText().toInt();
        int m2_rpm = ui->disp_rpm_m2->document()->toPlainText().toInt();

        dutyCycle_m1 += m1->update((m1_rpm - rpm_m1), m1_rpm);
        dutyCycle_m2 += m2->update((m2_rpm - rpm_m2), m2_rpm);

        QString commandOne = QChar::fromLatin1(M1_SET_DUTYCYCLE) + QString::number(dutyCycle_m1);
        QString commandTwo = QChar::fromLatin1(M2_SET_DUTYCYCLE) + QString::number(dutyCycle_m2);


        emit sendCommand(commandOne);
        emit sendCommand(commandTwo);
    }
}

void MainWindow::on_pushButton_clicked()
{
    rpm_m1 = ui->text_rpm_m1->text().toInt();
    rpm_m2 = ui->text_rpm_m2->text().toInt();
}

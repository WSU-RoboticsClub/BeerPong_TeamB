#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <iostream>
#include <ctime>
#include <QString>
#include "pid_controller.h"

#ifdef _WIN32
#include <Windows.h>
#elif __linux
#include <dirent.h>
#endif

#define M1_STATUS_DUTYCYCLE 0x01
#define M2_STATUS_DUTYCYCLE 0x02
#define M1_STATUS_CURRENT   0x03
#define M2_STATUS_CURRENT   0x04
#define M1_SET_DUTYCYCLE    0x05
#define M2_SET_DUTYCYCLE    0x06
#define M1_READ_RPM         0x07
#define M2_READ_RPM         0x08
#define M1_STATUS_RPM       0x09
#define M2_STATUS_RPM       0x0A

#define PID_FPS 60 // This denotes how frequently the pid controller updates

using namespace std;

class PortReader;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void sendCommand(QString command);

private slots:

    void on_button_set_targets_clicked();\
    void updateData(QString data);
    void populatePorts();
    void on_button_exit_clicked();
    void updateControllers();

    void on_button_openClose_clicked();

    void on_select_port_activated(const QString &arg1);

    void on_radioButton_toggled(bool checked);

    void on_radioButton_2_toggled(bool checked);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    PortReader *reader;
    QPalette *disabled;
    QPalette *enabled;
    QTimer *updatePorts;
    bool usePID;
    PID_Controller *m1, *m2;
    QTimer *updatePID;
    int rpm_m1, rpm_m2;
};


#include "portreader.hpp"

unsigned int convert(const char *buf);

#endif // MAINWINDOW_H

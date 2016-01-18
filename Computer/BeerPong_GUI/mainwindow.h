#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <iostream>
#include <ctime>
#include <QString>

#ifdef _WIN32
#include <Windows.h>
#elif __linux
#include <dirent.h>
#endif

#define MOTOR1_RPMS 0x11
#define MOTOR2_RPMS 0x12
#define MOTOR1_GOAL 0x31
#define MOTOR2_GOAL 0x32

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

    void on_button_openClose_clicked();

    void on_select_port_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    PortReader *reader;
    QPalette *disabled;
    QPalette *enabled;
    QTimer *updatePorts;
};


#include "portreader.hpp"

unsigned int convert(const char *buf);

#endif // MAINWINDOW_H

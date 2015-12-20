#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <iostream>
\

#include "Packetizer.hpp"

using std::cout;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void refresh_gui();
    void reset_gui();
    void on_button_getsync_clicked();

    void on_button_set_targets_clicked();

    void on_button_reset_clicked();

    void on_button_exit_clicked();

private:
    Ui::MainWindow *ui;
    Packetizer *port;
    QTimer *refresh, *reset;
    QPalette *disabled;
};

int convert(unsigned char *buf);

#endif // MAINWINDOW_H

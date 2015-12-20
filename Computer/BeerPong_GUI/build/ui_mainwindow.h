/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label_rpm_m1;
    QLabel *label_rpm_m2;
    QTextEdit *disp_rpm_m1;
    QTextEdit *disp_rpm_m2;
    QPushButton *button_getsync;
    QLabel *label_targets;
    QFrame *line;
    QSpinBox *spinBox_target_m1;
    QSpinBox *spinBox_target_m2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *button_set_targets;
    QPushButton *button_reset;
    QPushButton *button_exit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(498, 265);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_rpm_m1 = new QLabel(centralWidget);
        label_rpm_m1->setObjectName(QStringLiteral("label_rpm_m1"));
        label_rpm_m1->setGeometry(QRect(20, 30, 91, 16));
        label_rpm_m2 = new QLabel(centralWidget);
        label_rpm_m2->setObjectName(QStringLiteral("label_rpm_m2"));
        label_rpm_m2->setGeometry(QRect(20, 70, 91, 16));
        disp_rpm_m1 = new QTextEdit(centralWidget);
        disp_rpm_m1->setObjectName(QStringLiteral("disp_rpm_m1"));
        disp_rpm_m1->setGeometry(QRect(110, 30, 121, 31));
        disp_rpm_m1->setReadOnly(true);
        disp_rpm_m2 = new QTextEdit(centralWidget);
        disp_rpm_m2->setObjectName(QStringLiteral("disp_rpm_m2"));
        disp_rpm_m2->setGeometry(QRect(110, 70, 121, 31));
        disp_rpm_m2->setReadOnly(true);
        button_getsync = new QPushButton(centralWidget);
        button_getsync->setObjectName(QStringLiteral("button_getsync"));
        button_getsync->setGeometry(QRect(150, 170, 85, 27));
        button_getsync->setCheckable(false);
        label_targets = new QLabel(centralWidget);
        label_targets->setObjectName(QStringLiteral("label_targets"));
        label_targets->setGeometry(QRect(270, 10, 59, 17));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(240, 0, 20, 221));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        spinBox_target_m1 = new QSpinBox(centralWidget);
        spinBox_target_m1->setObjectName(QStringLiteral("spinBox_target_m1"));
        spinBox_target_m1->setGeometry(QRect(320, 50, 91, 27));
        spinBox_target_m1->setMinimum(-15000);
        spinBox_target_m1->setMaximum(15000);
        spinBox_target_m1->setSingleStep(100);
        spinBox_target_m1->setValue(1);
        spinBox_target_m2 = new QSpinBox(centralWidget);
        spinBox_target_m2->setObjectName(QStringLiteral("spinBox_target_m2"));
        spinBox_target_m2->setGeometry(QRect(320, 90, 91, 27));
        spinBox_target_m2->setMinimum(-15000);
        spinBox_target_m2->setMaximum(15000);
        spinBox_target_m2->setSingleStep(100);
        spinBox_target_m2->setValue(1);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(260, 50, 51, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(260, 90, 59, 17));
        button_set_targets = new QPushButton(centralWidget);
        button_set_targets->setObjectName(QStringLiteral("button_set_targets"));
        button_set_targets->setGeometry(QRect(260, 170, 85, 27));
        button_reset = new QPushButton(centralWidget);
        button_reset->setObjectName(QStringLiteral("button_reset"));
        button_reset->setGeometry(QRect(10, 170, 51, 27));
        button_exit = new QPushButton(centralWidget);
        button_exit->setObjectName(QStringLiteral("button_exit"));
        button_exit->setGeometry(QRect(410, 170, 85, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 498, 27));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_rpm_m1->setText(QApplication::translate("MainWindow", "Motor 1 RPMs: ", 0));
        label_rpm_m2->setText(QApplication::translate("MainWindow", "Motor 2 RPMs: ", 0));
        button_getsync->setText(QApplication::translate("MainWindow", "Get Sync", 0));
        label_targets->setText(QApplication::translate("MainWindow", "Targets", 0));
        label->setText(QApplication::translate("MainWindow", "Motor 1", 0));
        label_2->setText(QApplication::translate("MainWindow", "Motor 2", 0));
        button_set_targets->setText(QApplication::translate("MainWindow", "Set Targets", 0));
        button_reset->setText(QApplication::translate("MainWindow", "Reset", 0));
        button_exit->setText(QApplication::translate("MainWindow", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

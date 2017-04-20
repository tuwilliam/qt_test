/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *Btn_save;
    QSlider *horizontalSlider;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_bin;
    QLabel *label_skeleton;
    QPushButton *Btn_extract;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QScrollBar *verticalScrollBar;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1300, 803);
        QIcon icon;
        icon.addFile(QStringLiteral(":/leo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Btn_save = new QPushButton(centralWidget);
        Btn_save->setObjectName(QStringLiteral("Btn_save"));
        Btn_save->setGeometry(QRect(130, 700, 101, 31));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(20, 510, 160, 26));
        horizontalSlider->setMaximum(255);
        horizontalSlider->setOrientation(Qt::Horizontal);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 700, 81, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 561, 431));
        label->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 230)"));
        label_bin = new QLabel(centralWidget);
        label_bin->setObjectName(QStringLiteral("label_bin"));
        label_bin->setGeometry(QRect(810, 10, 461, 341));
        label_bin->setStyleSheet(QStringLiteral("background-color:rgb(255, 230, 200)"));
        label_skeleton = new QLabel(centralWidget);
        label_skeleton->setObjectName(QStringLiteral("label_skeleton"));
        label_skeleton->setGeometry(QRect(810, 400, 461, 341));
        label_skeleton->setStyleSheet(QStringLiteral("background-color:rgb(230, 255, 255)"));
        Btn_extract = new QPushButton(centralWidget);
        Btn_extract->setObjectName(QStringLiteral("Btn_extract"));
        Btn_extract->setGeometry(QRect(720, 710, 75, 23));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 570, 54, 12));
        label_2->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 230)"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 570, 54, 12));
        label_3->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 230)"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(220, 570, 54, 12));
        label_4->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 230)"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(320, 570, 54, 12));
        label_5->setStyleSheet(QStringLiteral("background-color:rgb(255, 255, 230)"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(220, 550, 54, 12));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(120, 550, 54, 12));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 550, 54, 12));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(320, 550, 54, 12));
        verticalScrollBar = new QScrollBar(centralWidget);
        verticalScrollBar->setObjectName(QStringLiteral("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(1280, 20, 16, 160));
        verticalScrollBar->setOrientation(Qt::Vertical);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1300, 21));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "VideoTest", 0));
        Btn_save->setText(QApplication::translate("MainWindow", "exit", 0));
        pushButton->setText(QApplication::translate("MainWindow", "display", 0));
        label->setText(QString());
        label_bin->setText(QString());
        label_skeleton->setText(QString());
        Btn_extract->setText(QApplication::translate("MainWindow", "extract", 0));
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "stop y", 0));
        label_7->setText(QApplication::translate("MainWindow", "start y", 0));
        label_8->setText(QApplication::translate("MainWindow", "start x", 0));
        label_9->setText(QApplication::translate("MainWindow", "stop y", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

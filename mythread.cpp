include "mythread.h"
#include <QtCore/QTime>
#include <QtCore/QTimer>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MyThread::MyThread()
    : QThread()
{

}

MyThread::~MyThread()
{

}

void MyThread::run()
{
    m_timer = new QTimer ;
    connect(m_timer , SIGNAL(timeout()) , this , SLOT(slot_time())) ;
    m_timer->start(25) ;
    exec() ;
}

QImage image_ske_ext;
Mat image_bin_ext;

void MyThread::slot_time()
{
    skeleton(image_bin_ext);
    image_ske_ext = Mat2QImage(image_bin_ext);
}

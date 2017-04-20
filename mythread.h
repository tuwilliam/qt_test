#ifndef MYTHREAD_H
#define MYTHREAD_H


#include <QtCore/QThread>

class QTimer ;
class MyThread : public QThread
{
    Q_OBJECT

public:
    MyThread();
    ~MyThread();
protected:
    void run() ;
public slots:
    void slot_time() ;
private:
    QTimer *m_timer ;
friend class MainWindow;
};

#endif // MYTHREAD_H

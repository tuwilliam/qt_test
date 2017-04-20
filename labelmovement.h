#ifndef LABELMOVEMENT
#define LABELMOVEMENT
#include <QApplication>
#include <QLabel>
#include <QMouseEvent>
class EventLabel : public QLabel
{
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    //void resize();
};


#endif // LABELMOVEMENT


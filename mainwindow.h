#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QImage>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QTimer>
#include <QMouseEvent>

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include <opencv2/opencv.hpp>

#include <iostream>

using namespace cv;
using namespace std;

QImage Mat2QImage(const cv::Mat& mat);
void skeleton(Mat &srcimage);
//void skeleton(Mat &Input);
//vector<int> GetFlags(int a[],int length);
extern QImage image_ske_ext;
extern Mat image_bin_ext;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //QGraphicsScene *scene;
    QImage img;
    QTimer *timer;
    VideoCapture cap;
    Mat frame;
    int binaryvlaue;
    Mat GrayImage;
    Mat BinaryImage;
private slots:
    void on_Btn_save_clicked();
    void on_horizontalSlider_valueChanged(int value);
    void slot_readFarme();
    void on_pushButton_clicked();
    void on_Btn_extract_clicked();
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;
};




#endif // MAINWINDOW_H

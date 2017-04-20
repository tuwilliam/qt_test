#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mythread.h"
#include "QDebug"

QImage Mat2QImage(const cv::Mat& mat)
{
    // 8-bits unsigned, NO. OF CHANNELS = 1
    if(mat.type() == CV_8UC1)
    {
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        // Set the color table (used to translate colour indexes to qRgb values)
        image.setColorCount(256);
        for(int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        // Copy input Mat
        uchar *pSrc = mat.data;
        for(int row = 0; row < mat.rows; row ++)
        {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    }
    // 8-bits unsigned, NO. OF CHANNELS = 3
    else if(mat.type() == CV_8UC3)
    {
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    else if(mat.type() == CV_8UC4)
    {
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image.copy();
    }
    else
    {
        return QImage();
    }
}

int x_1 = 0;
int y_1 = 0;
int x_2= 0;
int y_2 = 0;
int areawidth = 0;
int areaheight = 0;
bool getbox = false;
Rect box;

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton) //??????
    {
        box.width = 0;
        box.height = 0;

        getbox = false;
        box.x = event->x() - 20;
        if(box.x < 0)
            box.x = 0;
        ui->label_2->setText(QString("%1")
                             .arg(QString::number(box.x)));
        box.y = event->y() - 20;
        if(box.y < 0)
            box.y = 0;
        ui->label_3->setText(QString("%1")
                             .arg(QString::number(box.y)));
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton) //??????
    {
        x_2 = event->x() - 20;
        if(x_2 > frame.cols)
            x_2 = frame.cols;
        ui->label_4->setText(QString("%1")
                             .arg(QString::number(x_2)));
        y_2 = event->y() - 20;
        if(y_2 > frame.rows)
            y_2 = frame.rows;

        qDebug() << "frame.cols" << frame.cols;
        qDebug() << "frame.rows" << frame.rows;

        printf("%d\n",frame.rows);
        ui->label_5->setText(QString("%1")
                             .arg(QString::number(y_2)));
        box.width = x_2 - box.x;
        box.height = y_2 - box.y;
        getbox = true;
        qDebug() << box.x <<"  " << box.y <<"  " << x_2 <<"  " << box.height <<"\n";
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    x_2 = event->x() - 20;
    y_2 = event->y() - 20;
    box.width = x_2 - box.x;
    box.height = y_2 - box.y;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer   = new QTimer(this);

    ui->horizontalSlider->setValue(200);

    connect(timer, SIGNAL(timeout()), this, SLOT(slot_readFarme()));

    Mat image = imread("C:\\Users\\Tu-William\\Desktop\\qt_opencv_test\\raspberry.bmp");
    cvtColor(image, GrayImage, CV_BGR2GRAY);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Btn_save_clicked()
{
    cap.~VideoCapture();
    exit(0);
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    binaryvlaue = value;
}

void MainWindow::on_pushButton_clicked()
{
    // open the default camera using default API
    cap.open(0);
    // check if we succeeded
    if (!cap.isOpened()) {
        cerr << "ERROR! Unable to open camera\n";
        exit(0);
    }
    timer->start(25);

    cap.read(frame);
    if (frame.empty()) {
        cerr << "ERROR! blank frame grabbed\n";
        return ;
    }
    //ui->label_bin->resize(frame.cols, frame.rows);
   // ui->label->setMouseTracking(true);
    //ui->label->show();
   // threadA->start();
}


void MainWindow::slot_readFarme()
{
         // wait for a new frame from camera and store it into 'frame'
         cap.read(frame);
         // check if we succeeded
         if (frame.empty()) {
             cerr << "ERROR! blank frame grabbed\n";
             return ;
         }
         // show live and wait for a key with timeout long enough to show images
         QImage image = Mat2QImage(frame);
         //Mat japan = imread("japan.jpg");
         //QImage image = Mat2QImage(japan);
         if(image.isNull())
             {
                return;
             }
             else
             {
                 ui->label_bin->setPixmap(QPixmap::fromImage(image));  // ??????label?

             }
         cvtColor(frame, GrayImage, CV_BGR2GRAY);
         threshold(GrayImage, BinaryImage, binaryvlaue, 255, CV_THRESH_BINARY);
         rectangle(BinaryImage, box, Scalar(255, 255, 0), 2);
         QImage image_bin = Mat2QImage(BinaryImage);
         ui->label->resize(frame.cols, frame.rows);
         ui->label->setPixmap(QPixmap::fromImage(image_bin));

         if(getbox)
         {

             Mat BinartImageTemp = BinaryImage(Rect(box.x, box.y, box.width, box.height));
             skeleton(BinartImageTemp);
             QImage image_skeleton = Mat2QImage(BinartImageTemp);
             ui->label_skeleton->resize(BinartImageTemp.cols, BinartImageTemp.rows);
             ui->label_skeleton->setPixmap(QPixmap::fromImage(image_skeleton));
         }

}



void skeleton(Mat &srcimage)//???????????
{
    vector<Point> deletelist1;
    int Zhangmude[9];
    int nl = srcimage.rows;
    int nc = srcimage.cols;
    while (true)
    {
        for (int j = 1; j < (nl - 1); j++)
        {
            uchar* data_last = srcimage.ptr<uchar>(j - 1);
            uchar* data = srcimage.ptr<uchar>(j);
            uchar* data_next = srcimage.ptr<uchar>(j + 1);
            for (int i = 1; i < (nc - 1); i++)
            {
                if (data[i] == 255)
                {
                    Zhangmude[0] = 1;
                    if (data_last[i] == 255) Zhangmude[1] = 1;
                    else  Zhangmude[1] = 0;
                    if (data_last[i + 1] == 255) Zhangmude[2] = 1;
                    else  Zhangmude[2] = 0;
                    if (data[i + 1] == 255) Zhangmude[3] = 1;
                    else  Zhangmude[3] = 0;
                    if (data_next[i + 1] == 255) Zhangmude[4] = 1;
                    else  Zhangmude[4] = 0;
                    if (data_next[i] == 255) Zhangmude[5] = 1;
                    else  Zhangmude[5] = 0;
                    if (data_next[i - 1] == 255) Zhangmude[6] = 1;
                    else  Zhangmude[6] = 0;
                    if (data[i - 1] == 255) Zhangmude[7] = 1;
                    else  Zhangmude[7] = 0;
                    if (data_last[i - 1] == 255) Zhangmude[8] = 1;
                    else  Zhangmude[8] = 0;
                    int whitepointtotal = 0;
                    for (int k = 1; k < 9; k++)
                    {
                        whitepointtotal = whitepointtotal + Zhangmude[k];
                    }
                    if ((whitepointtotal >= 2) && (whitepointtotal <= 6))
                    {
                        int ap = 0;
                        if ((Zhangmude[1] == 0) && (Zhangmude[2] == 1)) ap++;
                        if ((Zhangmude[2] == 0) && (Zhangmude[3] == 1)) ap++;
                        if ((Zhangmude[3] == 0) && (Zhangmude[4] == 1)) ap++;
                        if ((Zhangmude[4] == 0) && (Zhangmude[5] == 1)) ap++;
                        if ((Zhangmude[5] == 0) && (Zhangmude[6] == 1)) ap++;
                        if ((Zhangmude[6] == 0) && (Zhangmude[7] == 1)) ap++;
                        if ((Zhangmude[7] == 0) && (Zhangmude[8] == 1)) ap++;
                        if ((Zhangmude[8] == 0) && (Zhangmude[1] == 1)) ap++;
                        if (ap == 1)
                        {
                            if ((Zhangmude[1] * Zhangmude[7] * Zhangmude[5] == 0) && (Zhangmude[3] * Zhangmude[5] * Zhangmude[7] == 0))
                            {
                                deletelist1.push_back(Point(i, j));
                            }
                        }
                    }
                }
            }
        }
        if (deletelist1.size() == 0) break;
        for (size_t i = 0; i < deletelist1.size(); i++)
        {
            Point tem;
            tem = deletelist1[i];
            uchar* data = srcimage.ptr<uchar>(tem.y);
            data[tem.x] = 0;
        }
        deletelist1.clear();

        for (int j = 1; j < (nl - 1); j++)
        {
            uchar* data_last = srcimage.ptr<uchar>(j - 1);
            uchar* data = srcimage.ptr<uchar>(j);
            uchar* data_next = srcimage.ptr<uchar>(j + 1);
            for (int i = 1; i < (nc - 1); i++)
            {
                if (data[i] == 255)
                {
                    Zhangmude[0] = 1;
                    if (data_last[i] == 255) Zhangmude[1] = 1;
                    else  Zhangmude[1] = 0;
                    if (data_last[i + 1] == 255) Zhangmude[2] = 1;
                    else  Zhangmude[2] = 0;
                    if (data[i + 1] == 255) Zhangmude[3] = 1;
                    else  Zhangmude[3] = 0;
                    if (data_next[i + 1] == 255) Zhangmude[4] = 1;
                    else  Zhangmude[4] = 0;
                    if (data_next[i] == 255) Zhangmude[5] = 1;
                    else  Zhangmude[5] = 0;
                    if (data_next[i - 1] == 255) Zhangmude[6] = 1;
                    else  Zhangmude[6] = 0;
                    if (data[i - 1] == 255) Zhangmude[7] = 1;
                    else  Zhangmude[7] = 0;
                    if (data_last[i - 1] == 255) Zhangmude[8] = 1;
                    else  Zhangmude[8] = 0;
                    int whitepointtotal = 0;
                    for (int k = 1; k < 9; k++)
                    {
                        whitepointtotal = whitepointtotal + Zhangmude[k];
                    }
                    if ((whitepointtotal >= 2) && (whitepointtotal <= 6))
                    {
                        int ap = 0;
                        if ((Zhangmude[1] == 0) && (Zhangmude[2] == 1)) ap++;
                        if ((Zhangmude[2] == 0) && (Zhangmude[3] == 1)) ap++;
                        if ((Zhangmude[3] == 0) && (Zhangmude[4] == 1)) ap++;
                        if ((Zhangmude[4] == 0) && (Zhangmude[5] == 1)) ap++;
                        if ((Zhangmude[5] == 0) && (Zhangmude[6] == 1)) ap++;
                        if ((Zhangmude[6] == 0) && (Zhangmude[7] == 1)) ap++;
                        if ((Zhangmude[7] == 0) && (Zhangmude[8] == 1)) ap++;
                        if ((Zhangmude[8] == 0) && (Zhangmude[1] == 1)) ap++;
                        if (ap == 1)
                        {
                            if ((Zhangmude[1] * Zhangmude[3] * Zhangmude[5] == 0) && (Zhangmude[3] * Zhangmude[1] * Zhangmude[7] == 0))
                            {
                                deletelist1.push_back(Point(i, j));
                            }
                        }
                    }
                }
            }
        }
        if (deletelist1.size() == 0) break;
        for (size_t i = 0; i < deletelist1.size(); i++)
        {
            Point tem;
            tem = deletelist1[i];
            uchar* data = srcimage.ptr<uchar>(tem.y);
            data[tem.x] = 0;
        }
        deletelist1.clear();
    }

}


void MainWindow::on_Btn_extract_clicked()
{
    skeleton(BinaryImage);
    QImage image_skeleton = Mat2QImage(BinaryImage);
    ui->label_skeleton->setPixmap(QPixmap::fromImage(image_skeleton));
}

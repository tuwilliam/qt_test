#-------------------------------------------------
#
# Project created by QtCreator 2017-02-28T20:26:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_opencv_test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui



INCLUDEPATH += D:\opencv\build\include
INCLUDEPATH += D:\opencv\build\include\opencv
INCLUDEPATH += D:\opencv\build\include\opencv2

LIBS+=  D:\Qt\opencv\lib\libopencv_calib3d320.dll.a\
        D:\Qt\opencv\lib\libopencv_core320.dll.a\
        D:\Qt\opencv\lib\libopencv_features2d320.dll.a\
        D:\Qt\opencv\lib\libopencv_flann320.dll.a\
        D:\Qt\opencv\lib\libopencv_highgui320.dll.a\
        D:\Qt\opencv\lib\libopencv_imgproc320.dll.a\
        D:\Qt\opencv\lib\libopencv_ml320.dll.a\
        D:\Qt\opencv\lib\libopencv_objdetect320.dll.a\
        D:\Qt\opencv\lib\libopencv_video320.dll.a\
        D:\Qt\opencv\lib\libopencv_ml320.dll.a\
        D:\Qt\opencv\lib\libopencv_photo320.dll.a\
        D:\Qt\opencv\lib\libopencv_shape320.dll.a\
        D:\Qt\opencv\lib\libopencv_stitching320.dll.a\
        D:\Qt\opencv\lib\libopencv_ts320.a\
        D:\Qt\opencv\lib\libopencv_videostab320.dll.a\
        D:\Qt\opencv\lib\libopencv_imgcodecs320.dll.a\
        D:\Qt\opencv\lib\libopencv_videoio320.dll.a

RESOURCES += \
    pic.qrc

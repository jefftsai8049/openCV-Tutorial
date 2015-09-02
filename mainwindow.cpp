#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString fileName = QFileDialog::getOpenFileName();
    cv::Mat img;
    img = cv::imread(fileName.toStdString(),CV_8UC1);
    cv::imshow("Picture",img);
    cv::Mat binaryImg = img.clone();
//    cv::threshold(img,binaryImg,127,255,0);

        for(int i=0;i<img.rows;i++)
        {
            for(int j=0;j<img.cols;j++)
            {
                if(img.at<uchar>(i,j) > 127)
                {
                    binaryImg.at<uchar>(i,j) = 255;
                }

                else
                {
                    binaryImg.at<uchar>(i,j) = 0;
                }
            }
        }
    cv::imshow("Binary",binaryImg);

}

MainWindow::~MainWindow()
{
    delete ui;
}

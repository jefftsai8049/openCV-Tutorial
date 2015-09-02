#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //get file name
    QString fileName = QFileDialog::getOpenFileName();

    //read image file
    cv::Mat img;
    img = cv::imread(fileName.toStdString());

    //show image
    cv::imshow("Picture",img);

    //clone image
    cv::Mat binaryImg = img.clone();

    //thresholding
    for(int i=0;i<img.rows;i++)
    {
        for(int j=0;j<img.cols;j++)
        {

            if(img.at<cv::Vec3b>(i,j)[2] == 255 && img.at<cv::Vec3b>(i,j)[0] == 0 &&img.at<cv::Vec3b>(i,j)[1] == 0)
            {
                //binaryImg.at<cv::Vec3b>(i,j) = cv::Vec3b(255,255,255);
                //0 -> blue
                //1 -> green
                //2 -> red


                //for(int m=0;m<img.channels();m++)
                //{
                //    binaryImg.data[i*img.cols*img.channels()+j*img.channels()+m] = 255;
                //}

                binaryImg.at<cv::Vec3b>(i,j)[0] = 255;
                binaryImg.at<cv::Vec3b>(i,j)[1] = 255;
                binaryImg.at<cv::Vec3b>(i,j)[2] = 255;
            }
            else
            {
                binaryImg.at<cv::Vec3b>(i,j)[0] = 0;
                binaryImg.at<cv::Vec3b>(i,j)[1] = 0;
                binaryImg.at<cv::Vec3b>(i,j)[2] = 0;
            }
        }
    }
    cv::imshow("Binary",binaryImg);

}

MainWindow::~MainWindow()
{
    delete ui;
}

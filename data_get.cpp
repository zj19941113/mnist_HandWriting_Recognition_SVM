#include <opencv2/opencv.hpp> 
#include <iostream> 
#include <stdio.h>
using namespace std; 
using namespace cv; 

/*
在OpenCV的安装路径下，搜索digits，可以得到一张图片，图片大小为1000*2000,
有0-9的10个数字，每5行为一个数字，总共50行，共有5000个手写数字，每个数字块大小为20*20
*/
int main() 
{ 
    char ad[128]={0}; 
    int filename = 0,filenum=0; 
    Mat img = imread("digits.png"); 
    Mat gray; 
    cvtColor(img, gray, CV_BGR2GRAY); 
    int b = 20; 
    int m = gray.rows / b; // 50 
    int n = gray.cols / b; // 100
    int offsetRow; //行上的偏移量 
    int offsetCol; //列上的偏移量 
    int i,j;

    for (i = 0; i < m; i++) 
    { 
        offsetRow = i*b;
        if(i%5==0&&i!=0) 
        { 
            filename++; 
            filenum=0; 
        } 
        for (j = 0; j < n; j++) 
        { 
            offsetCol = j*b;
            sprintf(ad, "/home/zhoujie/cProject/svm_numbers/data/%d/%d.jpg",filename,filenum++); 
            //截取20*20的小块
            Mat tmp; 
            gray(Range(offsetRow, offsetRow + b), Range(offsetCol, offsetCol + b)).copyTo(tmp); 
            imwrite(ad,tmp); 
        } 
    } 
    return 0;
}

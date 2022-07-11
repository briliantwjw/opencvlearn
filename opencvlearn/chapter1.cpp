#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

void main()
{
	string path = "resources/test.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDial, imgerode;

	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(img, imgBlur,Size(5,5),3,0);
	Canny(imgBlur, imgCanny,50,150);
	Mat kernal = getStructuringElement(MORPH_RECT, Size(3,3));
	dilate(imgCanny, imgDial,kernal);

	erode(imgDial, imgerode, kernal);

	imshow("Imageshow",img);
	imshow("Imagegray", imgGray);
	imshow("ImageBlur", imgBlur);
	imshow("ImageCanny", imgCanny);
	imshow("ImageDialaton", imgDial);
	imshow("ImageErode", imgerode);

	waitKey(0);
}
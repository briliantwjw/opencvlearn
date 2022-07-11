#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>


using namespace cv;
using namespace std;

Mat imgHSV,master;

int Hmin = 0, Smin = 0, Vmin = 0;
int Hmax = 179, Smax = 255, Vmax = 255;


int main()
{
	string path = "resources/shapes.png";

	Mat img;

	img = imread(path);
	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	namedWindow("TackerHSV",WINDOW_AUTOSIZE);
	createTrackbar("SET_Hmin", "TackerHSV", &Hmin, 179);
	createTrackbar("SET_Hmax", "TackerHSV", &Hmax, 179);
	createTrackbar("SET_Smin", "TackerHSV", &Smin, 255);
	createTrackbar("SET_Smax", "TackerHSV", &Smax, 255);
	createTrackbar("SET_Vmin", "TackerHSV", &Vmin, 255);
	createTrackbar("SET_Vmax", "TackerHSV", &Vmax, 255);

	while (true)
	{
		Scalar lower(Hmin, Smin, Vmin);
		Scalar high(Hmax, Smax, Vmax);
		inRange(imgHSV, lower, high, master);

		imshow("originIMG", img);
		imshow("IMGHSV", imgHSV);
		imshow("IMGmaster", master);
		waitKey(1);
	}
	return 0;

}
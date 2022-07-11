#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include<iostream>


using namespace cv;
using namespace std;

int main()
{
	string path = "resources/test.png";

	Mat img;
	img = imread(path);

	CascadeClassifier faceclassifier;
	faceclassifier.load("resources/haarcascade_frontalface_default.xml");

	/*if (faceclassifier.empty())
	{
		cout << "detect failture" << endl;
	}*/
	vector<Rect> faces;
	faceclassifier.detectMultiScale(img,faces,1.1,10);
	for (int i = 0; i < faces.size(); i++)
	{
		rectangle(img, faces[i].tl(), faces[i].br(),Scalar(255,0,255),3);
	}



	imshow("test_image", img);
	waitKey(0);
}
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp> //Allows us to work with cascade files
#include <iostream>

using namespace cv;
using namespace std;


void main() {
	string path = "Resources/Group.jpg"; //Face test image: Zahraa.jpg (me) or Group.jpg (Sample Group photo)
	Mat img = imread(path);



	CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml"); //loads cascade to detect faces

	if (faceCascade.empty()) { cout << "XML file not loaded" << endl; }

	vector<Rect> faces; //to detect the face and store it, we need to store binding boxes(rectangles)
	faceCascade.detectMultiScale(img, faces, 1.1, 10); //detects objects and returns as rectangles

	for (int i = 0; i < faces.size(); i++) {

		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0, 0, 255), 3); //draws rectangel from tl: top left of the face to br: bottom right of the face
	}

	imshow("Image Test", img);
	waitKey(0);


}
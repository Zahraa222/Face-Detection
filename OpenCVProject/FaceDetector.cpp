#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp> //Allows us to work with cascade files
#include <iostream>

using namespace cv;
using namespace std;


void main() {
	string type;
	Mat img;
	CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml"); //loads cascade to detect faces
	if (faceCascade.empty()) { cout << "XML file not loaded" << endl; } //outputs when XML is loaded or invalid
	vector<Rect> faces; //to detect the face and store it, we need to store binding boxes(rectangles)


	//user input for facial detection type
	cout << "Test image or live webcam? type 'image' or 'webcam': ";
	cin >> type;

	//Image Facial detection
	if ((type == "image") || (type == "Image")){
		string path = "Resources/Group.jpg"; //Face test image: Zahraa.jpg (me) or Group.jpg (Sample Group photo)
		img = imread(path);
		faceCascade.detectMultiScale(img, faces, 1.3, 5); //detects objects and returns as rectangles

		for (int i = 0; i < faces.size(); i++) {

			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0, 0, 255), 3); //draws rectangel from tl: top left of the face to br: bottom right of the face

			//Top right corner, text output will display the number of faces visible
			if (faces.size() == 1) {
				putText(img, to_string(faces.size()) + " Face Found :)", Point(10, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 0), 2);
			}

			else {
				putText(img, to_string(faces.size()) + " Faces Found :)", Point(10, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 0), 2);
			}
		}

		imshow("Image Test", img);
		waitKey(0);
	}


	//Live webcam Facial detection
	if (type == "webcam" || type == ("Webcam")) {
		VideoCapture video(0);

		while (true) {
			video.read(img);
			faceCascade.detectMultiScale(img, faces, 1.3, 5); //detects objects and returns as rectangles

			for (int i = 0; i < faces.size(); i++) {

				//draws rectangle from tl: top left of the face to br: bottom right of the face, Rectangle color: red
				rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0, 0, 255), 3); 

				//Top right corner, text output will display the number of faces visible
				if (faces.size() == 1) {
					putText(img, to_string(faces.size()) + " Face Found :)", Point(10, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 0), 2);
				}

				else {
					putText(img, to_string(faces.size()) + " Faces Found :)", Point(10, 40), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 0, 0), 2);
				}
			
			}

			imshow("Live Detection", img);
			waitKey(1);



		}
	}
	else {
		cout << "invlaid input. Please type 'image' or 'webcam'";
		cin >> type;
	}


	system("PAUSE");
}
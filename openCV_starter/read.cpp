#include "read.h"

void read_img() {

	string path = "Resources/lambo.png"; // image path
	Mat img = imread(path);  // read image from path
	imshow("Image", img);   // show image on a window
	waitKey();   // wait until a key is pressed

}

void read_video() {

	string path = "Resources/test_video.mp4";  // video path
	VideoCapture cap(path);   // create a VideoCapture object for video
	Mat img;

	while (true) {
		cap.read(img);   // read each frame of video
		imshow("Image", img);  // display each frame in a window
		waitKey(1);  // wait for a key to be pressed
	}
}

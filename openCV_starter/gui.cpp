#include "gui.h"

// Initialize trackbar values for HSV color space filtering
int hmin = 0, smin = 0, vmin = 0;
int hmax = 179, smax = 255, vmax = 255;

void create_gui() {

	// Load an image and convert it to the HSV color space
	string path = "Resources/shapes.png";
	Mat img, imgHSV, mask;
	img = imread(path);
	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	// Create a GUI window with trackbars to adjust the HSV color range
	namedWindow("Trackbars", (640, 200));
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Val Min", "Trackbars", &vmin, 255);
	createTrackbar("Val Max", "Trackbars", &vmax, 255);

	// Loop until the user exits the program
	while (true) {

		// Create scalar values from the current trackbar values for the lower and upper range of the HSV color space filtering
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);

		// Create a binary image mask using the inRange function and the current HSV color range
		inRange(imgHSV, lower, upper, mask);

		// Display the original image, the image in HSV color space, and the binary image mask
		imshow("Image", img);
		imshow("Image HSV", imgHSV);
		imshow("Image mask", mask);

		// Wait for a key press event to occur for 1 millisecond, and then continue the loop
		waitKey(1);
	}
}
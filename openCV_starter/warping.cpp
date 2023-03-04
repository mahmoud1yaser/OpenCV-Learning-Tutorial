#include "warping.h"

// Initialize variables for width and height of the resulting image
float w = 250, h = 350;

// Initialize matrices for perspective transformation
Mat matrix, imgWarp;

// Perform perspective warp on an input image
void warp() {

	// Read input image
	string path = "Resources/cards.jpg";
	Mat img = imread(path);

	// Define source and destination points for perspective transformation
	Point2f src[4] = { {529,142}, {771,190}, {405, 395}, {674,457} };
	Point2f dst[4] = { {0.0f,0.0f}, {w,.0f}, {.0f, h}, {w,h} };

	// Compute the perspective transformation matrix
	matrix = getPerspectiveTransform(src, dst);

	// Apply the perspective transformation to the input image
	warpPerspective(img, imgWarp, matrix, Point(w, h));

	// Visualize source points on the input image
	for (int i = 0; i < 4; i++) {
		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
	}

	// Display the input image and the warped image
	imshow("Image", img);
	imshow("Image Warp", imgWarp);

	// Wait until a key is pressed
	waitKey(0);
}
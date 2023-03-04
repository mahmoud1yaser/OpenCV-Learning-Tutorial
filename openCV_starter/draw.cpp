#include "draw.h"


// Define a function called draw
void draw() {
	// Create a blank image of size 512x512 with 3 channels of unsigned char type with blue color
	Mat img(512, 512, CV_8UC3, Scalar(255, 0, 0));

	// Draw a filled circle on the image with center (256, 256), radius 155, and color (0, 69, 245)
	circle(img, Point(256, 256), 155, Scalar(0, 69, 245), FILLED);

	// Draw a filled rectangle on the image with top-left corner at (130, 226), bottom-right corner at (382, 286), and color (0, 255, 245)
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(0, 255, 245), FILLED);

	// Draw a line on the image from point (130, 296) to point (382, 296) with color (255, 255, 255) and thickness 2
	line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);

	// Add text "Hello there!" to the image with font type FONT_HERSHEY_DUPLEX, scale factor 0.8, color (0,69,255), and thickness 2, at position (137, 262)
	putText(img, "Hello there!", Point(137, 262), FONT_HERSHEY_DUPLEX, 0.8, Scalar(0, 69, 255), 2);

	// Show the image
	imshow("image", img);

	// Wait until a key is pressed
	waitKey(0);
}
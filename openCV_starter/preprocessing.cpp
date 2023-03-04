#include "preprocessing.h"

void resize_crop() {

	// Load an image from a file
	string path = "Resources/test.png";
	Mat img, imgResize, imgCrop;
	img = imread(path);

	// Resize the image
	resize(img, imgResize, Size(), 0.5, 1.9);

	// Crop the image using a region of interest (ROI)
	Rect roi(100, 100, 300, 250);
	imgCrop = img(roi);

	// Display the original image, resized image, and cropped image
	imshow("Image", img);
	imshow("Image Reize", imgResize);
	imshow("Image Crop", imgCrop);

	waitKey(0);
}

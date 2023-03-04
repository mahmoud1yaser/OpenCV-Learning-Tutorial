#include "filter.h"


void filter() {                   // definition of the function 'filter'
	string path = "Resources/test.png";  // path to the image file
	Mat img = imread(path);         // read image from the file
	Mat imgGray;                    // declare a new image to hold the grayscale image
	Mat imgBlur;                    // declare a new image to hold the blurred image
	Mat imgCanny, imgDia, imgErode; // declare new images for the edge, dilation, and erosion effects

	cvtColor(img, imgGray, COLOR_BGR2GRAY);        // convert the color image to grayscale
	GaussianBlur(img, imgBlur, Size(5, 5), 5, 0);  // apply a Gaussian blur filter to the image
	Canny(imgBlur, imgCanny, 50, 150);             // detect edges in the blurred image using the Canny algorithm

	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5)); // create a 5x5 rectangular structuring element
	dilate(imgCanny, imgDia, kernel);                          // apply dilation effect to the edge image
	erode(imgDia, imgErode, kernel);                           // apply erosion effect to the dilated image

	imshow("image", img);                 // display the original image in a window
	imshow("gray image", imgGray);         // display the grayscale image in a window
	imshow("blur image", imgBlur);         // display the blurred image in a window
	imshow("edge image", imgCanny);        // display the edge image in a window
	imshow("Dialation", imgDia);           // display the dilated image in a window
	imshow("erode image", imgErode);       // display the eroded image in a window

	waitKey(0);                           // wait for a key event in any of the windows
}

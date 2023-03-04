#include "detect_shapes.h"

// This function takes in a binary image and its corresponding original image, finds contours in the image, 
// classifies the contours into shapes, draws and labels the shapes on the original image.
void getContours(Mat imgDia, Mat img) {

	// Declare variables to store the contours and their hierarchy, and a string to hold the object type
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	string objectType;

	// Find contours in the binary image
	findContours(imgDia, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	// Declare vectors to store the polygonal approximation of the contours and the bounding rectangles of the shapes
	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());

	// Iterate through all the contours found
	for (int i = 0; i < contours.size(); i++) {

		// Calculate the area of each contour and print it to the console
		int area = contourArea(contours[i]);
		cout << area << endl;

		// Check if the contour is large enough to be a shape
		if (area > 1000) {

			// Approximate the contour as a polygon and calculate its bounding rectangle
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			boundRect[i] = boundingRect(conPoly[i]);

			// Classify the shape based on the number of vertices in the polygonal approximation
			int objCor = (int)conPoly[i].size();

			if (objCor == 3) { objectType = "Triangle"; }
			else if (objCor == 4) {
				// Check if the bounding rectangle is square-like to classify the shape as a square, 
				// otherwise classify it as a rectangle
				float aspRatio = boundRect[i].width / boundRect[i].height;
				if (aspRatio > 0.95 && aspRatio < 1.05) {
					objectType = "Square";
				}
				else { objectType = "Rect"; }
			}
			// Classify shapes with more than 4 vertices as circles
			if (objCor > 4) { objectType = "Circle"; }
			// Classify triangles again to override the classification of squares and rectangles with 3 vertices
			if (objCor == 3) { objectType = "Triangle"; }

			// Draw the shape on the original image by drawing the polygonal approximation, 
			// the bounding rectangle, and adding a label for the shape type
			putText(img, objectType, { boundRect[i].x, boundRect[i].y - 5 }, FONT_HERSHEY_PLAIN, 0.8, Scalar(0, 69, 255), 1.5);
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);

		}
	}
}

void detect_shapes() {

	// Load the image
	string path = "Resources/shapes.png";
	Mat img, imgGray, imgBlur, imgCanny, imgDia, imgErode;
	img = imread(path);

	// Preprocessing
	// Convert the image to grayscale
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	// Apply Gaussian blur to the image
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	// Apply Canny edge detection to the image
	Canny(imgBlur, imgCanny, 25, 75);

	// Create a kernel for morphological operations
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
	// Dilate the image using the kernel
	dilate(imgCanny, imgDia, kernel);

	// Find contours in the image and identify shapes
	getContours(imgDia, img);

	// Display the image
	imshow("image", img);

	// Wait for a key press
	waitKey(0);

}

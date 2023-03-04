// header file for shape detection using OpenCV
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// function to find contours in a binary image, classify shapes and draw them on the original image
void getContours(Mat imgDia, Mat img);

// function to detect shapes in an image
void detect_shapes();
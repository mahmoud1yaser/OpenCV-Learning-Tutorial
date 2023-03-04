// Header file for detecting faces in a video stream using OpenCV
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Function to detect faces in a video stream and draw rectangles around them
void detect_faces();
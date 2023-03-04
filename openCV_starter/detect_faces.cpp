// Include necessary header files for OpenCV and standard input/output operations
#include "detect_faces.h"

void detect_faces() {
	// Create a VideoCapture object to read the video stream from default camera
	VideoCapture cap(0);
	// Declare a Mat object to hold each frame of the video stream
	Mat img;
	// Create a CascadeClassifier object to detect faces in the frame
	CascadeClassifier faceCascade;
	// Load the pre-trained classifier from the given file
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");
	// Declare a vector to hold the detected faces
	vector<Rect> faces;
	// Start an infinite loop to read the video stream and detect faces
	while (true) {
		// Read a frame from the video stream and store it in the Mat object
		cap.read(img);
		// Detect faces in the current frame and store their locations in the vector
		faceCascade.detectMultiScale(img, faces, 1.1, 10);
		// Loop through the detected faces and draw a rectangle around each one
		for (int i = 0; i < faces.size(); i++) {
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
			// Add text to label the detected face as "Person"
			putText(img, "Person", faces[i].tl(), FONT_HERSHEY_PLAIN, 3, Scalar(255, 0, 0), 5);
		}
		// Display the frame with the detected faces
		imshow("Image", img);
		// Wait for 10 milliseconds for a key event
		waitKey(10);
	}
}
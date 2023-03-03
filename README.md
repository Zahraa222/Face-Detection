# Facial Detection Project

Using C++ and openCV, This code performs facial detection on either a static image or a live video feed from a webcam using the OpenCV library. It loads a Haar cascade classifier XML file to detect faces, reads an input image or captures a live video feed, and applies the face detection algorithm to the image or frames.

If the input type is an image, the code reads the image, detects faces, draws a bounding box around each face, and displays the image with the bounding boxes and the number of faces detected. If the input type is a webcam, the code captures the live video feed, detects faces in each frame, draws a bounding box around each face, and displays the frame with the bounding boxes and the number of faces detected.

The code uses various OpenCV functions such as imread, imshow, waitKey, CascadeClassifier, detectMultiScale, rectangle, and putText.

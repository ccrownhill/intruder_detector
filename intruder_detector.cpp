#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/video.hpp>
#include <opencv2/imgproc.hpp>
#include <unistd.h>
#include <string.h>

using namespace std;
using namespace cv;

const float MEAN_FLOW_THRESHOLD = 0.3;

int main(int argc, char *argv[])
{
	char output_image_file[100] = "intruder_image.jpg";
	char opt;
	while((opt = getopt(argc, argv, "o:h")) != -1) {
		switch(opt) {
			case 'o':
				strncpy(output_image_file, optarg, 100);
				break;
			case 'h':
				cout << "Usage: " << argv[0] << " [-o output_image_file] [-h]" << endl;
				return 0;
			default:
				cerr << "Usage: " << argv[0] << " [-o output_image_file] [-h]" << endl;
				return 1;
		}
	}

	VideoCapture camera(0);
	if (!camera.isOpened()) {
		cerr << "ERROR: Could not open camera" << endl;
		return 1;
	}
	namedWindow("frame", WINDOW_NORMAL);
	sleep(10); // Give some time to exit the room after starting the program

	Mat frame1, prvs;
	camera >> frame1;
	cvtColor(frame1, prvs, COLOR_BGR2GRAY);
	while (true) {
		Mat frame2, next;
		camera >> frame2;
		if (!frame2.empty()) {
			cvtColor(frame2, next, COLOR_BGR2GRAY);
			Mat flow(prvs.size(), CV_32FC2);
			calcOpticalFlowFarneback(prvs, next, flow, 0.5, 3, 15, 3, 5, 1.2, 0);
			imshow("frame", frame2);

			if (abs(mean(flow)[0]) + abs(mean(flow)[1]) > MEAN_FLOW_THRESHOLD) {
				cout << "Intruder detected" << endl;
				imwrite(output_image_file, frame2);
			}

			prvs = next;
		}
		if (waitKey(1) >= 0) // quit if a key is pressed
			break;
	}
	return 0;
}

intruder_detector: intruder_detector.cpp
	g++ -I/usr/include/opencv4 intruder_detector.cpp -o intruder_detector -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lopencv_imgproc

CC = g++
INCS = -I/usr/include/opencv4
LIBS = -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lopencv_imgproc
CPPFLAGS = -Wall -Os $(INCS) $(LIBS)

intruder_detector: intruder_detector.cpp
	$(CC) $^ $(CPPFLAGS) -o $@

clean:
	rm intruder_detector

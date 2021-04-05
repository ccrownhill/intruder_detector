# Intruder Detector

This small program will constantly get frames from a computers webcam and save an image to a specified directory if an intruder was detected (or any other motion happens). This is done using opencv.

If the program should be run in the background the `imshow` output as well as the output to `stdout` can be removed so that the only output will be a saved image. That way if the image is saved to a network drive one can remotely see if there is an intruder in the room where the camera is located.

Of course this program is very basic and can be extended in multiple ways.

## Compilation

Before compiling make sure that *opencv* is properly installed.

With `make`:

```
$ make intruder_detector
```

This will just execute this command:

```
$ g++ intruder_detector.cpp -Wall -Os -I/usr/include/opencv4 -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_videoio -lopencv_video -lopencv_imgproc -o intruder_detector
```

## Usage

Just run

```
$ ./intruder_detector
```

to save the intruder images in the current directory as `intruder_detector.jpg`.

To specify the output image file use:

```
$ ./intruder_detector -o /path_to_output_image_directory/image_file_name.jpg
```

To show the usage message use:

```
$ ./intruder_detector -h
```

To quit the program press any key while hovering over the video output window or just CTRL-C (in the terminal where the program is being executed).

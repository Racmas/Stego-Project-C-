@ECHO OFF

IF NOT EXIST bin ( MKDIR bin)
start pwsh -NoExit -Command "g++ -Wall -Wextra -Wpedantic -std=c++17 -Iexternal/include -Iexternal/include/opencv2 prog/source/main.cpp -Lexternal/lib -llibopencv_calib3d455 -llibopencv_core455 -llibopencv_dnn455 -llibopencv_features2d455 -llibopencv_flann455 -llibopencv_highgui455 -llibopencv_imgcodecs455 -llibopencv_imgproc455 -llibopencv_ml455 -llibopencv_objdetect455 -llibopencv_photo455 -llibopencv_stitching455 -llibopencv_video455 -llibopencv_videoio455 -o bin/test.exe"

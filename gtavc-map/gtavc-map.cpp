#include <iostream>

#include <opencv2/core/core.hpp>
#include <Eigen/Core>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/eigen.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
int main()
{
	Mat I = imread("./map.png", IMREAD_UNCHANGED);
	//resize(I, I, cv::Size(), 0.25, 0.25);

	if (I.empty())
	{
		std::cout << "!!! Failed imread(): image not found" << std::endl;
		return -1;
	}

	namedWindow("Display window", CV_WINDOW_NORMAL);
	imshow("Display window", I);
	waitKey(0);
	return 0;
}
#include <iostream>

#include <opencv2/core/core.hpp>
#include <Eigen/Core>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/eigen.hpp>
using namespace cv;
int main()
{
	Mat I = imread("C:\\Users\\Deniz\\Pictures\\IMG_14540.jpg", IMREAD_UNCHANGED);
	if (I.empty())
	{
		std::cout << "!!! Failed imread(): image not found" << std::endl;
		// don't let the execution continue, else imshow() will crash.
	}

	namedWindow("Display window", CV_WINDOW_AUTOSIZE);// Create a window for display.
	imshow("Display window", I);
	waitKey(0);
	return 0;
}
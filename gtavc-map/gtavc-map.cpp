#include <iostream>

#include <opencv2/core/core.hpp>
#include <Eigen/Core>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/eigen.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "write_memory.h"

#define _WIN32_WINNT _WIN32_WINNT_WIN7 /**
										* Set minimum operating system targeted to Win7 so the PROCESS_ALL_ACCESS flag doesnt get huge
										* check https://docs.microsoft.com/en-us/windows/win32/winprog/using-the-windows-headers for 
										* further information if you need to target a older OS
										*/

using namespace cv;

float mouseData[5];

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
	if (event == EVENT_LBUTTONDOWN)
	{
		std::cout << "M1 (" << -(478 - x) << ", " << 414 - y << ")" << std::endl;  /**
																					* -478 and -414 to fix the (0,0) point
																					* becasue the Vice City takes the middle of the the map
																					* in a weird spot. Also inverse the x to match
																					* the Vice City way of coords
																					*/
		mouseData[0] = -(478 - x);
		mouseData[1] = 414 - y;
		writeCoords(mouseData[0]* 3.91232329951, mouseData[1]* 3.91232329951,15.0);
	}
	else if (event == EVENT_RBUTTONDOWN)
	{
		std::cout << "M2 (" << -(478- x)  << ", " << 414 -y  << ")" << std::endl;
		mouseData[2] = -(478 - x);
		mouseData[3] = 414 - y;
	}
	else if (event == EVENT_MBUTTONDOWN)
	{
		std::cout << "M3 (" << -(478 - x) << ", " << 414 - y << ")" << std::endl;
		mouseData[4] = -(478 - x);
		mouseData[5] = 414 - y;
	}
	/**
	else if (event == EVENT_MOUSEMOVE)
	{
		std::cout << "M_MOVED (" << x << ", " << y << ")" << std::endl;

	}
	*/
}

int main()
{
	Mat I = imread("./map.png", IMREAD_UNCHANGED);
	//resize(I, I, cv::Size(), 0.25, 0.25);

	if (I.empty())
	{
		std::cout << "Can't find/read image!" << std::endl;
		return -1;
	}

	namedWindow("Display window", WINDOW_GUI_EXPANDED);
	imshow("Display window", I);
	setMouseCallback("Display window", CallBackFunc, NULL);
	waitKey(0);
	return 0;
}
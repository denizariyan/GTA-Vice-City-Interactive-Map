/**
MIT License

Copyright (c) 2020 Deniz Ariyan

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <iostream>

#include <opencv2/core/core.hpp>
#include <Eigen/Core>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/eigen.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <Windows.h>
#include "write_memory.h"
#include "overlay_image.h"

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
		writeCoords(mouseData[0]* 3.91232329951, mouseData[1]* 3.91232329951,15.0); /*
																					 * Passing 15 as Z for testing purposes, multiplying by 3.9 
																					 * to scale from the programs map to games map 
																					 */
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
	else if (event == EVENT_MOUSEMOVE)  // Will be used to display the mous over x,y
	{
		std::cout << "M_MOVED (" << x << ", " << y << ")" << std::endl;

	}
	*/
}

int main()
{
	Mat imageMap = imread("./map.png", IMREAD_UNCHANGED);
	Mat imageMarker = imread("./marker.png", IMREAD_UNCHANGED);
	resize(imageMarker, imageMarker, cv::Size(), 0.25, 0.25);

	if (imageMap.empty() || imageMarker.empty())
	{
		std::cout << "Can't find/read image(s)!" << std::endl;
		system("pause");
		return -1;
	}
	namedWindow("Display window", WINDOW_GUI_EXPANDED);
	while (true)
	{
		overlayImage(imageMap, imageMarker, imageMap, cv::Point(100, 100));
		imshow("Display window", imageMap);
		setMouseCallback("Display window", CallBackFunc, NULL);
		waitKey(1);
		Sleep(50);
	}


	return 0;
}

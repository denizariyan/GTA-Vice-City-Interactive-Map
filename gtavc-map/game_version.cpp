#include <windows.h>
#include <conio.h>
#include <iostream>
#include <vector>
#include "multi_offset_pointer.h"
#include <string>


DWORD versionOffset() {

	DWORD v1_0 = 0x667BF0; 
	DWORD v1_1 = 0x667C40;
	DWORD v1_1_STEAM = 0xA402ED;
	DWORD v1_0_JP = 0xACD0A2;

	DWORD pid; // Process ID
	HWND hwnd; // Windows handle
	hwnd = FindWindow(NULL, L"GTA: Vice City");

	if (!hwnd)
	{
		std::cout << "Could not find the Vice City window! Run the game before starting the exe!\n";
		system("pause");
	}

	GetWindowThreadProcessId(hwnd, &pid);
	HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS, 0, pid); // PROCESS_VM_READ can be used for less memory usage when using an OS older than win7

	if (!phandle)
	{
		std::cout << "Could not get handle! Make sure you are running the exe with admin priv\n";
		system("pause");
	}


	DWORD address_v1_0 = FindDMAAddy(phandle, v1_0, { 0x0 });
	DWORD address_v1_1 = FindDMAAddy(phandle, v1_1, { 0x0 });
	DWORD address_v1_0_JP = FindDMAAddy(phandle, v1_0_JP, { 0x0 });

	if (address_v1_0 == 0x53E58955)
	{
		return 0;
	}
	else if (address_v1_1 == 0x53E58955)
	{
		return 8;
	}
	else if (address_v1_0_JP == 0x6AEC8B55)
	{
		return -0X2FF8;
	}
	else
	{
		std::cout << "CAN NOT DETERMINE GAME VERSION!" << std::endl;
		return 0;
	}
}
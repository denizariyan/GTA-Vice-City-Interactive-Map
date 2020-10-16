#include <windows.h>
#include <conio.h>
#include <iostream>
#include <vector>
#include "multi_offset_pointer.h"
#include <string>

float read_coords(char axisToRead) {

	float value = 0.0;
	
	DWORD baseAddress = 0x07E4B8C; // Memory pointer for player
	DWORD offsetX = 0x34;
	DWORD offsetY = 0x38;
	DWORD offsetZ = 0x3C;

	DWORD address;

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

	if (axisToRead == 'X')
	{
		address = FindDMAAddy(phandle, baseAddress, { offsetX }); // Have to be recalculated for each game instance because this is a dynamic address
		ReadProcessMemory(phandle, (void*)address, &value, sizeof(value), NULL);
		value = (478 + value / 3.91232329951)- 28.37500; // -28 to set the needle of the marker as the pointer, 3.9 to scale from game map to emulated map
	}
	else if (axisToRead == 'Y')
	{
		address = FindDMAAddy(phandle, baseAddress, { offsetY });
		ReadProcessMemory(phandle, (void*)address, &value, sizeof(value), NULL);
		value = (414 - value / 3.91232329951)-54; // -54 to set the needle of the marker as the pointer, 3.9 to scale from game map to emulated map
	}
	else
	{
		address = FindDMAAddy(phandle, baseAddress, { offsetZ });
	}

	float scaledResult = value;
	return scaledResult;
	

}

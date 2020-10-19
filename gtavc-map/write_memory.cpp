#include <windows.h>
#include <conio.h>
#include <iostream>
#include <vector>
#include "multi_offset_pointer.h"
#include "game_version.h"


void writeCoords(float x, float y, float z = -100.0) { /**
														* Setting Z value to anything less than or equal to -100 means that the game engine will automatically
													    * calculate the ground Z for us. Works only on areas that are loaded, assign a value if teleporting to 
													    * an area that is not loaded, not required otherwise. Will select the top of a building instead of
														* ground floor if possible
														*/
														
	DWORD offset = versionOffset();
	DWORD baseAddress = 0x07E4B8C + offset; // Memory pointer for player
	DWORD offsetX = 0x34;
	DWORD offsetY = 0x38;
	DWORD offsetZ = 0x3C;

	DWORD pid; // Process ID
	HWND hwnd; // Windows handle
	hwnd = FindWindow(NULL, L"GTA: Vice City");
	if (!hwnd)
	{
		std::cout << "Could not find the Vice City window! Run the game before starting the exe!\n";
		system("pause");
	}

	GetWindowThreadProcessId(hwnd, &pid);
	HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS, 0, pid);
	if (!phandle)
	{
		std::cout << "Could not get handle! Make sure you are running the exe with admin priv\n";
		system("pause");
	}

	DWORD addressX = FindDMAAddy(phandle, baseAddress, { offsetX }); // Have to be recalculated for each game instance because this is a dynamic address
	DWORD addressY = FindDMAAddy(phandle, baseAddress, { offsetY });
	DWORD addressZ = FindDMAAddy(phandle, baseAddress, { offsetZ });

	WriteProcessMemory(phandle, (void*)addressX, &x, sizeof(x), NULL);
	WriteProcessMemory(phandle, (void*)addressY, &y, sizeof(y), NULL);
	WriteProcessMemory(phandle, (void*)addressZ, &z, sizeof(z), NULL);

}
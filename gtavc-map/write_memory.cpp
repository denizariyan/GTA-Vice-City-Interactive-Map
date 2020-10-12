#include <windows.h>
#include <conio.h>
#include <iostream>

using namespace std;

int writeCoords(int x, int y) {

	DWORD address = 0x07E4B8C; // Memory offset for players left-right angle
	DWORD offsetX = 0x34;
	DWORD offsetY = 0x38;
	DWORD offsetZ = 0x3C;

	DWORD pid; // Process ID
	HWND hwnd; // Windows handle
	hwnd = FindWindow(NULL, L"GTA: Vice City");
	if (!hwnd)
	{
		cout << "Could not find the Vice City window! Run the game before starting the exe!\n";
		cin.get();
		return -1;
	}

	GetWindowThreadProcessId(hwnd, &pid);
	HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS, 0, pid);
	if (!phandle)
	{
		cout << "Could not get handle! Make sure you are running the exe with admin priv\n";
		cin.get();
		return -1;

	}

	WriteProcessMemory(phandle, baseAddress, (LPCVOID)newString, sz, &bytes_written);

		//ReadProcessMemory(phandle, (void*)address, &value, sizeof(value), 0);
		

	return 0;
}
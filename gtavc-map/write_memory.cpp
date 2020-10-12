#include <windows.h>
#include <conio.h>
#include <iostream>

using namespace std;

int writeCoords(int x, int y) {
	int result;

	DWORD address = 0x7E48CC; // Memory offset for players left-right angle

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



		//ReadProcessMemory(phandle, (void*)address, &value, sizeof(value), 0);
		

	return result;
}
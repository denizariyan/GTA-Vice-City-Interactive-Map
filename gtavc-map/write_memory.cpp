#include <windows.h>
#include <conio.h>
#include <iostream>
#include <vector>

using namespace std;

uintptr_t FindDMAAddy(HANDLE hProc, uintptr_t ptr, vector<unsigned int> offsets) // https://stackoverflow.com/a/56310967
{
	for (unsigned int i = 0; i < offsets.size(); ++i)
	{
		ReadProcessMemory(hProc, (BYTE*)ptr, &ptr, sizeof(ptr), 0);
		ptr += offsets[i];
	}
	return ptr;
}

int writeCoords(int x, int y) {

	DWORD baseAddress = 0x07E4B8C; // Memory pointer for player
	DWORD offsetX = 0x34;
	DWORD offsetY = 0x38;
	DWORD offsetZ = 0x3C;

	DWORD address = baseAddress + offsetX;

	float value = 0.0;

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
	WriteProcessMemory(phandle, (void*)address, &value, sizeof(value), NULL);
	//cout << address;

	//ReadProcessMemory(phandle, (void*)address, &value, sizeof(value), 0);
		
	cout << fixed<<address;

	return 0;
}
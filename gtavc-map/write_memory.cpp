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

void writeCoords(float x, float y, float z = -100.0) {

	DWORD baseAddress = 0x07E4B8C; // Memory pointer for player
	DWORD offsetX = 0x34;
	DWORD offsetY = 0x38;
	DWORD offsetZ = 0x3C;

	DWORD pid; // Process ID
	HWND hwnd; // Windows handle
	hwnd = FindWindow(NULL, L"GTA: Vice City");
	if (!hwnd)
	{
		cout << "Could not find the Vice City window! Run the game before starting the exe!\n";
		system("pause");
	}

	GetWindowThreadProcessId(hwnd, &pid);
	HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS, 0, pid);
	if (!phandle)
	{
		cout << "Could not get handle! Make sure you are running the exe with admin priv\n";
		system("pause");
	}

	DWORD addressX = FindDMAAddy(phandle, baseAddress, { offsetX });
	DWORD addressY = FindDMAAddy(phandle, baseAddress, { offsetY });
	DWORD addressZ = FindDMAAddy(phandle, baseAddress, { offsetZ });

	WriteProcessMemory(phandle, (void*)addressX, &x, sizeof(x), NULL);
	WriteProcessMemory(phandle, (void*)addressY, &y, sizeof(y), NULL);
	WriteProcessMemory(phandle, (void*)addressZ, &z, sizeof(z), NULL);

}
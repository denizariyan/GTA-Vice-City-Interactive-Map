#include <windows.h>
#include <conio.h>
#include <iostream>
#include <vector>

uintptr_t FindDMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets) // Credit for this function only: https://stackoverflow.com/a/56310967
{
	for (unsigned int i = 0; i < offsets.size(); ++i)
	{
		ReadProcessMemory(hProc, (BYTE*)ptr, &ptr, sizeof(ptr), 0);
		ptr += offsets[i];
	}
	return ptr;
}
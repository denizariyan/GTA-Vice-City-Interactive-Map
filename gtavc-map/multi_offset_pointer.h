#pragma once
#include <vector>
#include <windows.h>

uintptr_t FindDMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets);
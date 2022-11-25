#pragma once

#ifdef _WIN32
#include <windows.h>
#endif

extern "C" void SetConsoleOutputUtf8()
{
#ifdef _WIN32
    SetConsoleOutputCP(65001);
#endif
}
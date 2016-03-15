#include <stdio.h>
#include <windows.h>
#include "main.h"

void DLL_EXPORT PrintMessage(const LPCSTR sometext)
{
    puts("Test message to the console.");
    MessageBoxA(0, sometext, "DLL window XDDD LUL TOPKEK", MB_OK | MB_ICONINFORMATION);
}

int DLL_EXPORT AddNumbers(const int a1, const int a2)
{
    return (a1 + a2);
}

void DLL_EXPORT SetCoord(const short x, const short y)
{
    COORD myCoord = { x, y };
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handle, myCoord);
}

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            break;
        case DLL_PROCESS_DETACH:
            break;
        case DLL_THREAD_ATTACH:
            break;
        case DLL_THREAD_DETACH:
            break;
    }
    return TRUE;
}

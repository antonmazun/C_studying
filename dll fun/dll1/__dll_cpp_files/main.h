#pragma once

#include <windows.h>

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

void DLL_EXPORT PrintMessage(const LPCSTR sometext);
int DLL_EXPORT AddNumbers(const int a1, const int a2);
void DLL_EXPORT SetCoord(const short x, const short y);

#ifdef __cplusplus
}
#endif

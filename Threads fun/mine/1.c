#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

DWORD WINAPI MyThreadFunction(LPVOID lpParam)
{
    printf("The parameter: %u.\n", *(DWORD*)lpParam);
    return (0);
}

int main()
{
    DWORD dwThreadId, dwThrdParam = 1;
    HANDLE hThread;

    hThread = CreateThread( NULL, // default security abilities.
                           0, // default stack size.
                           MyThreadFunction, //thread function.
                           &dwThrdParam, // argument to thread function.
                           0, // use default creation flags.
                           &dwThreadId); // return thread identifier
    printf("The thread ID: %u.\n", dwThreadId);
    // Check the return value for success.
    // If smt goes wrong:
    if(NULL == hThread)
    {
        printf("CreateThread() failed, error: %u.\n", GetLastError());
    }
    else
        printf("CreateThread() worked correctly.");
    if(CloseHandle(hThread) != 0)
        printf("Handle to thread closed successfully.\n");
    return (0);
}

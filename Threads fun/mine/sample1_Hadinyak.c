#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <windows.h>
#include <conio.h>

struct Context
{
    int a;
    int b;
};

DWORD threadUpdateA(LPVOID);
DWORD threadUpdateB(LPVOID);
DWORD threadDraw(LPVOID);
DWORD threadDecreaseA(LPVOID);
DWORD threadDecreaseB(LPVOID);

HANDLE newThread(LPTHREAD_START_ROUTINE routine, struct Context * ctx)
{
    return CreateThread(
               NULL, // default security attributes
               0, // default stack size
               (LPTHREAD_START_ROUTINE) routine, // thread function
               (LPVOID)ctx, // thread function arguments
               0, // default creation flags
               NULL); // receive thread identifier
}

int main(void)
{
    // Source to fill
    struct Context context = {0,0};
    // Create set of threads and run them
    HANDLE hThreads[] = {
        newThread(threadUpdateA, &context),
        newThread(threadUpdateB, &context),
        newThread(threadDraw, &context),
    };
    // Wait in main thread
    _getch();
    // Create some more threads
    HANDLE decr1 = newThread(threadDecreaseA, &context);
    HANDLE decr2 = newThread(threadDecreaseB, &context);
    _getch();
    // Terminate threads and close them
    int i;
    for(i = 0; i < 3; i++)
    {
        TerminateThread(hThreads[i], 0);
        CloseHandle(hThreads[i]);
    }
    TerminateThread(decr1, 0);
    CloseHandle(decr1);
    TerminateThread(decr2, 0);
    CloseHandle(decr2);
    // End of the program here.
    _getch();
    puts("End of the program");
    return (0);
}

DWORD threadUpdateA(LPVOID args)
{
    struct Context *ctx = (struct Context *)args;
    while(TRUE) {
        ctx->a++;
        Sleep(20);
    }
}
DWORD threadUpdateB(LPVOID args)
{
    struct Context *ctx = (struct Context *)args;
    while(TRUE) {
        ctx->b += 2;
        Sleep(20);
    }
}

DWORD threadDecreaseA(LPVOID args)
{
    struct Context *ctx = (struct Context *)args;
    while(TRUE) {
        ctx->a -= 2;
        Sleep(20);
    }
}

DWORD threadDecreaseB(LPVOID args)
{
    struct Context *ctx = (struct Context *)args;
    while(TRUE) {
        ctx->b -= 3;
        Sleep(20);
    }
}

DWORD threadDraw(LPVOID args)
{
    struct Context *ctx = (struct Context *)args;
    while(TRUE) {
        system("cls");
        printf("A: %i\tB: %i\n", ctx->a, ctx->b);
        fflush(stdout);
        Sleep(20);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include <windows.h>
#include <conio.h>

#define LIMIT_VALUE 10
#define SLEEP_PRODUCER 45
#define SLEEP_CONSUMER 60

DWORD producer(LPVOID);
DWORD consumer(LPVOID);

HANDLE newThread(LPTHREAD_START_ROUTINE routine, int * context);

int main(void)
{
    // shared resource
    int value = 6;
    // create new threads
    HANDLE consumers[] = {
        newThread(consumer, &value),
        newThread(consumer, &value),
        newThread(consumer, &value),
        newThread(consumer, &value),
    };
    HANDLE producers[] = {
        newThread(producer, &value),
        newThread(producer, &value),
    };
    // wait in main thread
    while(!_kbhit()) {
        system("cls");
        printf("Value is [%i]", value);
        fflush(stdout);
        Sleep(10);
    }
    // Close threads and free allocated memory
    for(int i = 0; i < 2; i++)
        CloseHandle(producers[i]);
    for(int i = 0; i < 4; i++)
        CloseHandle(consumers[i]);
    // End of the program
    _getch();
    system("cls");
    puts("End of the program.");
    return (0);
}

DWORD producer(LPVOID args)
{
    int *param = (int *)args;
    while(TRUE) {
        if(*param < LIMIT_VALUE) {
            (*param)++;
            if(*param >= LIMIT_VALUE) {
                fprintf(stderr, "\n\nERROR, value is %i", *param);
                exit(1); // Failure
            }
        }
        Sleep(30);
    }
}

DWORD consumer(LPVOID args)
{
    int *param = (int *)args;
    while(TRUE) {
        if(*param > 0) {
            (*param)--;
            if(*param < 0) {
                fprintf(stderr, "\n\nERROR, value is %i", *param);
                exit(1); // Failure
            }
        }
        Sleep(45);
    }
}

HANDLE newThread(LPTHREAD_START_ROUTINE routine, int * context)
{
    return CreateThread(
                    NULL,
                    0,
                    (LPTHREAD_START_ROUTINE) routine,
                    (LPVOID) context,
                    0,
                    NULL);
}

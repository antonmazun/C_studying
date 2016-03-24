#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef void (*PrintMessage)(const LPCSTR sometext);
typedef int (*AddNumbers)(const int a1, const int a2);
typedef void (*SetCoord) (const short x, const short y);

int main()
{
    PrintMessage printMsg = NULL;
    AddNumbers addNmbrs = NULL;
    SetCoord setCrd = NULL;
    HINSTANCE hLib = LoadLibrary("dllSample.dll");
    if (NULL != hLib)
    {
        printMsg = (PrintMessage)GetProcAddress(hLib, "PrintMessage");
        addNmbrs = (AddNumbers)GetProcAddress(hLib, "AddNumbers");
        setCrd = (SetCoord)GetProcAddress(hLib, "SetCoord");
        if(NULL != printMsg)
        {
            printMsg("Hello from max func");
        }
        else
        {
            printf("Error on getting PrintMessage() function address!\n");
        }
        if(NULL != addNmbrs)
        {
            printf("Adding 2 and 5! Result is %d\n", addNmbrs(2,5));
        }
        else
        {
            printf("Error on getting AddNumbers() function address!\n");
        }
        if(NULL != setCrd)
        {
            puts("Putting on (5,5) position in console...");
            setCrd(5,5);
            printf("hello!");
        }
        else
        {
            printf("Error on getting AddNumbers() function address!\n");
        }

        //Free library resources
        FreeLibrary(hLib);
    }
    else
    {
        printf("Error on load library!\n");
    }
    return 0;

}

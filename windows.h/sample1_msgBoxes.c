#include <windows.h>
#include <tchar.h> // To simplify the transporting of code for international use
#include <stdio.h>

void firstWindow()
{
    const long dialogResult = MessageBox(
                 NULL,
                 TEXT("Hello, Windows!"),
                 TEXT("HelloMsg Title"),
                 MB_YESNOCANCEL | MB_DEFBUTTON2);
    if(dialogResult == IDCANCEL) {
        MessageBox(
                   NULL,
                   TEXT("Are you sure?"),
                   TEXT("Cancel?"),
                   MB_OK | MB_ICONWARNING);
    }
}

int CDECL MessageBoxPrintf(TCHAR * szCaption, TCHAR * szFormat, ...)
{
    TCHAR szBuffer[1024];
    va_list pArgList;
    va_start (pArgList, szFormat);
    _vsntprintf (szBuffer, sizeof(szBuffer)/sizeof(TCHAR), szFormat, pArgList);
    return MessageBox(NULL, szBuffer, szCaption, 0);
}

void secondWindow()
{
    int cxScreen, cyScreen;
    cxScreen = GetSystemMetrics(SM_CXSCREEN);
    cyScreen = GetSystemMetrics(SM_CYSCREEN);
    MessageBoxPrintf(TEXT("ScrnSize title"),
                     TEXT("The screen is %i pixels wide by %i pixels high"),
                     cxScreen, cyScreen);
}

int main()
{
    secondWindow();
    return 0;
}

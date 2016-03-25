#include <windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow)
{
   HWND hMainWnd;
   char szClassName[] = "MyClass";
   MSG msg;
   WNDCLASSEX wc;
   // Fill windows structure fields.
   wc.cbSize = sizeof(wc);
   wc.style = CS_HREDRAW | CS_VREDRAW;
   wc.lpfnWndProc = WndProc;
   wc.cbClsExtra = 0;
   wc.cbWndExtra = 0;
   wc.hInstance = hInstance;
   wc.hIcon = LoadIcon(NULL, IDC_ARROW);
   wc.hCursor = LoadCursor(NULL, IDC_ARROW);
   wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
   wc.lpszMenuName = NULL;
   wc.lpszClassName = szClassName;
   wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
   // Register window class.
   if(!RegisterClassEx(&wc))
   {
      MessageBox(NULL, "Cannot register class", "Error!", MB_OK);
      return (0);
   }
   // Create main window.
   hMainWnd = CreateWindow(
            szClassName,
            "A Hello1 Application",
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT,
            0,
            CW_USEDEFAULT,
            0,
            (HWND)NULL,
            (HMENU)NULL,
            (HINSTANCE)hInstance,
            NULL);
   if(!hMainWnd)
   {
      MessageBox(NULL, "Cannot create main window", "Error!", MB_OK);
      return (0);
   }
   // Showing a window.
   ShowWindow(hMainWnd, nCmdShow);
   UpdateWindow(hMainWnd);
   // While program runs - translate and dispatch messages
   while(GetMessage(&msg, NULL, 0, 0))
   {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
   }
   return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
   HDC hDC;
   PAINTSTRUCT ps;
   RECT rect;
   // Do something.
   switch(uMsg)
   {
   case WM_PAINT:
      hDC = BeginPaint(hWnd, &ps);
      GetClientRect(hWnd, &rect);
      DrawText(hDC, "Hello, World!", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
      EndPaint(hWnd, &ps);
      break;
   case WM_CLOSE:
      DestroyWindow(hWnd);
      break;
   case WM_DESTROY:
      PostQuitMessage(0);
      break;
   default:
      return DefWindowProc(hWnd, uMsg, wParam, lParam);
   }
   return (0);
}

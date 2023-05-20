
#include<windows.h>


//HIDE WINDOWS CONSOLE 
typedef HWND(WINAPI* GetConsoleWindowPtr)();

void HideConsoleWindow() {
    HMODULE hModule = GetModuleHandle("kernel32.dll");
    GetConsoleWindowPtr pGetConsoleWindow = (GetConsoleWindowPtr)GetProcAddress(hModule, "GetConsoleWindow");

    if (pGetConsoleWindow != NULL) {
        HWND hwnd = pGetConsoleWindow();
        ShowWindow(hwnd, SW_HIDE);
    }
}
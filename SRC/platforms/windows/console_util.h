
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

typedef HWND(WINAPI* GetConsoleWindowPtr)();
//HIDE WINDOWS CONSOLE 
void ShowHUDConsole() {
}
void HideHUDConsole(){   
}

void interactConsole(){
    char command[100];
    
    while (1) {
        printf("\n >> ");
        fgets(command, sizeof(command), stdin);
        
        // Remova o caractere de nova linha ('\n') lido pelo fgets
        command[strcspn(command, "\n")] = '\0';
        
        // Saia do loop se o usuário digitar "exit"
        if (strcmp(command, "exit") == 0) {
            break;
        }
        
        // Execute o comando usando a função system
        system(command);
    }
}

void ShowConsoleWindow() {
    HMODULE hModule = GetModuleHandle("kernel32.dll");
    GetConsoleWindowPtr pGetConsoleWindow = (GetConsoleWindowPtr)GetProcAddress(hModule, "GetConsoleWindow");

    if (pGetConsoleWindow != NULL) {
        HWND hwnd = pGetConsoleWindow();
        ShowWindow(hwnd, SW_SHOW);
    }
}

void HideConsoleWindow() {
    HMODULE hModule = GetModuleHandle("kernel32.dll");
    GetConsoleWindowPtr pGetConsoleWindow = (GetConsoleWindowPtr)GetProcAddress(hModule, "GetConsoleWindow");

    if (pGetConsoleWindow != NULL) {
        HWND hwnd = pGetConsoleWindow();
        ShowWindow(hwnd, SW_HIDE);
    }
}
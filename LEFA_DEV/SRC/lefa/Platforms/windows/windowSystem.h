#ifndef WINDOW_SYSTEM_HPP
#define WINDOW_SYSTEM_HPP

#include<windows.h>
#include<string.h>

 #define true 1
 #define false 0

extern int isRunning; //game running check

void engineCreateWindow(int width, int height);

void engineSetWindowTitle(const char* title);

void engineSetWindowIcon(const char* iconPath);

void onTimerUpdateCursor();

//Broke
//void engineGetWindowResolution(int& width, int& height);

int runEngineLoop(void (*renderFunction)());

void windowBorderless(int windowWidth, int windowHeight);

#endif // WINDOW_SYSTEM_HPP




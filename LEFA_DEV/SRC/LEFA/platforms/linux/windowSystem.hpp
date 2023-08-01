/*Open LEFA Project
2022-2023
*/
#ifndef WINDOW_SYSTEM_HPP
#define WINDOW_SYSTEM_HPP


#include<string.h>


extern bool isRunning; //game running check

void engineCreateWindow(int width, int height);

void engineSetWindowTitle(const char* title);

void engineSetWindowIcon(const char* iconPath);

//Broke Function
//void engineGetWindowResolution(int& width, int& height);

int runEngineLoop(void (*renderFunction)());

void windowBorderless(int windowWidth, int windowHeight);

#endif // WINDOW_SYSTEM_HPP

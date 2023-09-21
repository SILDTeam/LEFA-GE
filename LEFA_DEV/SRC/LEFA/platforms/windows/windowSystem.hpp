#ifndef WINDOW_SYSTEM_HPP
#define WINDOW_SYSTEM_HPP

#include<windows.h>
#include<string.h>

//static int FRAME_DELAY_MS = 10; // Defina o valor desejado para o atraso entre quadros (aproximadamente 60 FPS)


//static int frameCount = 0;
//static int fps = 0;
//static double lastTime = 0.0;

extern bool isRunning; //game running check

void engineCreateWindow(int width, int height);

void engineSetWindowTitle(const char* title);

void engineSetWindowIcon(const char* iconPath);

void onTimerUpdateCursor();

//Broke
//void engineGetWindowResolution(int& width, int& height);

int runEngineLoop(void (*renderFunction)());

void windowBorderless(int windowWidth, int windowHeight);

#endif // WINDOW_SYSTEM_HPP




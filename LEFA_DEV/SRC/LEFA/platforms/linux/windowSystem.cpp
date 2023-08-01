/*Open LEFA Project
2022-2023
*/
//X11 system for LINUX API

#include"windowSystem.hpp";

/*
//quick FiX
#ifndef __OFF_T_DEFINED
#define __OFF_T_DEFINED
typedef long long __off_t;
#endif
*/

#include<X11/Xlib.h>
#include<X11/Xutil.h>

#include <GL/gl.h>
#include <GL/glx.h>
/*
#include<X11/X.h>
#include<X11/Xlib.h>
#include<X11/Xutil.h>
#include<X11/Xlib-xcb.h>
#include<GL/glx.h>
#include<GL/gl.h>

#include<xcb/xcb.h>
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>


bool isRunning = true;
bool isWindowBorderless = false;
bool isWindowActive = true; // Variável para controlar se a janela do jogo está ativa ou não
int windowWidth;
int windowHeight;

// X11 Variables
Display* display;
Window window;
Screen* screen;
int screenId;
XEvent ev;




void engineCreateWindow(int width, int height)
{
    
    
}



int runEngineLoop(void (*renderFunction)())
{
    while(isRunning)
    {
        

        // Chama a função de renderização passada como parâmetro
        if (renderFunction != NULL) {
            renderFunction();
        }


    }

    // Libera recursos e encerra a janela
    // Implemente aqui o código para finalizar a janela corretamente

    return 0;

}

void engineSetWindowTitle(const char* title)
{
    // Define o título da janela
    //XStoreName(Display, window, title);
}

void engineSetWindowIcon(const char* iconPath)
{
}

void windowBorderless(int windowWidth, int windowHeight)
{
}

/*Open Project LEFA
    2022-2023*/

//Systems
#ifdef WIN32
    #define WIN32_LEAN_AND_MEAN
    #include"lefa/platforms/windows_header.h";
#endif //WIN32

/*
#ifdef LINUX
    #include<dlfcn.h>
    #include"lefa/platforms/linux_header.h";
#endif
*/

//OpenGL Loader GLAD
#include"lefa/render/glad/glad_gl.H";


/*  C / C++ LIBS
*/
//#include<iostream>
//#include<stdio.h> //fopen
//#include<stdlib.h>
//#include<string.h>

/* engine libs
*/

#include"lefa/engineArgs.h";
#include"lefa/file_manager.h";
//#include"eheader/glad_manager.h";
#include"lefa/console_msg.h";


void Render()
{
    glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.5f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.5f, -0.5f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, 0.5f);
    glEnd();
}

int main (int argc, char* argv[], char* envp[])
{

    gameVersion("WindowPoly","Demo");
    engineVersion();
    printLine("is a LEFA Demo to create a window with poly");

    /*Console Show or Hide*/
    ToggleConsoleWindow(argc, argv);

    int wWidth  = 0, 
        wHeight = 0; 

    wWidth =  800;
    wHeight = 600;

    printLine("wWidth: %d", wWidth);
    printLine("wHeight: %d", wHeight);

    engineCreateWindow(wWidth, wHeight);
    engineSetWindowTitle("WindowPoly");
    engineSetWindowIcon("glsaver.ico");

    gladLoadGL();

    engineGLoop(Render);

    return 0;
}
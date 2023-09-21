/*Open Project LEFA
    2022-2023*/

//Systems
#ifdef _WIN32
#   define WIN32_LEAN_AND_MEAN
#   include"lefa/platforms/windows_header.h";
#endif //WIN32


#ifdef _LINUX
#   include<dlfcn.h>
#   include"lefa/platforms/linux_header.h";
#endif

// C/C++ LIBS
#ifdef IN_CLIBS
#   include<iostream>
#   include<stdio.h> //fopen
#   include<stdlib.h>
#   include<string.h>
#endif

//Engine Files

    //OpenGL Loader GLAD
 #include"lefa/gl_manager.h";
  
//engine includes 

 #include"lefa/engineArgs.h";
 #include"lefa/file_manager.h";
 #include"lefa/console_msg.h";

bool isSomethingChanged = false;


void Render()
{
    //glClearColor(0.2f, 0.3f, 0.4f, 1.0f);

    if (isSomethingChanged) {
        // Faça a alteração que você deseja aqui, por exemplo, alterar a cor de fundo
        glClearColor(0.8f, 0.6f, 0.2f, 1.0f);
    } else {
        glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
    }
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.5f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.5f, -0.5f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, 0.5f);
    glEnd();

    if (keyInput(KEY_ESC))
    {   
        isRunning = false;
    }

    if (keyInput(KEY_E))
    {
        isSomethingChanged = true;
    }else {
        isSomethingChanged = false;
    }
    if(keyInput(KEY_U))
    {
        engineSetWindowTitle("00");
    }
    if(keyInput(KEY_I))
    {
        engineSetWindowTitle("22");
    }
    if(keyInput(KEY_B))
    {
        printf("Hello \n");
    }

    mouseInput();

    if (keyInput(KEY_Z))
    {
        windowBorderless(800, 600);
    }
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
        //
        wWidth =  800;
        wHeight = 600;

    printLine("wWidth: %d", wWidth);
    printLine("wHeight: %d", wHeight);

    engineCreateWindow(wWidth, wHeight);

    if (!engineCreateWindow)
    {
        isRunning = false;
        return -1;
    }


    engineSetWindowTitle("WindowPoly");
    engineSetWindowIcon("glsaver.ico");

    gladLoadGL();
    runEngineLoop(Render);

    return 0;
}

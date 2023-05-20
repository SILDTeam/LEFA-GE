/*Open Project LEFA
    2022-2023*/
#define MAX_TITLE_LENGTH 50

//#define WIN32

#ifdef WIN32
    #include<windows.h>
    //Resource Script
    #pragma w32res "win32.rc"
    #include"platforms/win32/console_util.h";
#endif

/*
#ifdef WIN64
    #include<windows.h>
    #pragma w64res "win64.rc"
    #include"platforms/win64/console_util.h";
#endif 
*/

#ifndef WINDEF_H_INCLUDED
    #define WINDEF_H_INCLUDED
    #include <windef.h>
#endif
/*include Glad First
  include Glut second*/

#include<GL/glad.h>
#include<GL/glut.h>


#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(0);

    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.0f, 0.5f);
    glEnd();

    glutSwapBuffers();
}

//typedef HWND(WINAPI* GetConsoleWindowPtr)();

//void HideConsoleWindow();  // Declaração da função definida em console_util.cpp

int main(int argc, char** argv)
{
    /*Extern Functions*/
    HideConsoleWindow();  // Chama a função para ocultar o console
   /*Open game Definition Config*/
    /*USRC = User Config*/
    FILE *usrc = fopen("res/GC_engine.lec", "r");

    if (!usrc) {
        //char *title = "Error!";
        //char *message = "a Error! user Config Not found \n"
                        //"the program will automatically \n"
                        //"create the user file \n"
                        //"do not modify the file again \n"
                        //"so this message does not appear \n";
       // MessageBox(NULL, message, title, MB_ICONEXCLAMATION | MB_OK);
        /*Create File*/
        FILE *usrc = fopen("res/GC_engine.lec", "w");
        fprintf(usrc, "\n //based engine default file"
                         "\n title=GL_Triangle;"
                         "\n wsize=800x600;"
                         "\n wpos=0x0;");
        fclose(usrc);


        printf("\n Error! : GC_engine.lec Not found!\n \n");
        system("pause");
    }

    char title[MAX_TITLE_LENGTH] = {0};
    int Width = 0, Height = 0, wPosX = 0, wPosY = 0;

    char line[100];
    fgets(line, sizeof(line), usrc);
    char *key = strtok(line, " ");
    char *value = strtok(NULL, "\n");

    fscanf(usrc, "//" , NULL);
    fscanf(usrc, "%s"   , &title);
    fscanf(usrc,  "%dx%d;", &Width, &Height);
    fscanf(usrc,  "%dx%d;", &wPosX, &wPosY);

    fclose(usrc);



    glutInit(&argc, argv);


    glutCreateWindow(title);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(Width, Height);
    glutInitWindowPosition(wPosX, wPosY);

/*_______________________________________________________________________________*/


    if (!gladLoadGL()) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    std::cout << "LEFA_GE V:30/04/2023 \n" ;
    std::cout << "Base OpenGl Version : 2.1 \n";
    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;

    GLuint program = glCreateProgram();

    const char* vertexShaderSource =
        "#version 120\n"
        "void main() {"
        "  gl_Position = gl_Vertex;"
        "}";

    const char* fragmentShaderSource =
        "#version 120\n"
        "void main() {"
        "  gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);"
        "}";

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "Vertex shader compilation failed\n" << infoLog << std::endl;
    }

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "Fragment shader compilation failed\n" << infoLog << std::endl;
    }

    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << "Shader program linking failed\n" << infoLog << std::endl;
    }

    glUseProgram(program);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
/*Open Project LEFA
    2022-2023*/

#ifdef WINDOWS
    #include<windows.h>
    //Resource Script
    #pragma w32res "win32.rc"
    #include"platforms/windows_header.h";
#endif


//#ifndef WINDEF_H_INCLUDED
    //#define WINDEF_H_INCLUDED
    //#include <windef.h>
//#endif

#ifdef LINUX
    #include<dlfcn.h>
    #include"platforms/linux_header.h";
#endif

/*  OpenGL LIBS
*/

#include<GL/glad.h> //(1) GLAD First
#include<GL/glut.h> //(2) GLUT Second

/*  C/C++ LIBS
*/
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* engine libs
*/

#include"header/file_manager.h";
#include"header/glad_manager.h";
#include"header/console_msg.h";

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

/**/

/**/

int main(int argc, char** argv)
{
/**/
    engineCompilation();
/**/

/*Other Functions*/
    // Console Window 
    if (argc > 1 && strcmp(argv[1], "-sw_console") == 0) {
        ShowConsoleWindow();
    } else {
        HideConsoleWindow();
    }



    /*Open game Definition Config*/
    /*USRC = User Config*/
    FILE *usrc = fopen("res/GC_engine.lec", "r");

    if (!usrc) 
    {
        ifGameConfigNotExist();
    }

    char line[256];
    char title[100] = "";

    char wsize[100];
    char wpos[100];

    int Width  = 0, 
        Height = 0, 
        wPosX  = 0, 
        wPosY  = 0;

    while (fgets(line, sizeof(line), usrc)) {
    if (strncmp(line, "//", 2) == 0) {
    // Is a Comment, ignore
    continue;
  }

  // looking for the key "title"
  if (strstr(line, "title") != NULL) {
    char* value = strchr(line, '"'); // Encontra a primeira aspa
    if (value != NULL) {
      value++; // Avança para o próximo caractere após a aspa inicial
      char* end = strchr(value, '"'); // Encontra a segunda aspa
      if (end != NULL) {
        *end = '\0'; // Substitui a segunda aspa por um terminador nulo
        strncpy(title, value, sizeof(title)); // Copia o conteúdo entre as aspas para o título
        break; // Não é necessário continuar lendo após encontrar o título
      }
    }
  }

}

printf("\n Title: %s \n \n", title);



    fclose(usrc);
/*________________________________________________________*/
    glutInit(&argc, argv);
    glutCreateWindow(title);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(Width, Height);
    glutInitWindowPosition(wPosX, wPosY);

/*_______________________________________________________*/
/*GLAD*/
    if (!gladLoadGL()) 
    {
        gladLoadGLERROR();
        return -1;
    }

    consoleEngineGLStatus();

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
        //std::cout << "Vertex shader compilation failed\n" << infoLog << std::endl;
        vertexERROR();
    }

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        //std::cout << "Fragment shader compilation failed\n" << infoLog << std::endl;
        fragERROR();
    }

    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    
    if (!success)
    {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        //std::cout << "Shader program linking failed\n" << infoLog << std::endl;
        shaderLinkERROR();
    }

    //glUseProgram(program);
/*GLAD*/


    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
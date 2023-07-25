#include<stdio.h>
#include<time.h>
#include<string.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


void printLine(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    printf("\n");
    va_end(args);
}



void gameVersion(const char* gameName, const char* version)
{
    printLine("%s / %s", gameName, version);
}

void engineVersion()
{
    printLine("LEFA Build: 25.07.23", ANSI_COLOR_GREEN);
}


//IGNORE
void meme()
{

	printf(" (\\_/)\n"
		   " ( ._.)\n"
		   " / >::<\n"
		   "\n");
}


void gladLoadGLERROR() 
    {
    printLine("Failed to initialize GLAD\n");
    }


void vertexERROR()
    {
    printLine("Vertex shader compilation failed\n");
    }


void fragERROR()
    {
    printLine("Fragment shader compilation failed\n");
    }

    
void shaderLinkERROR()
    {
    printLine("Shader program linking failed\n");
    }

/*
void engineCompilation()
{
    time_t currentTime;
    struct tm *localTime;
    char datetime[20];

    // Obter a hora atual
    currentTime = time(NULL);
    localTime = localtime(&currentTime);

    // Formatar a data e hora
    strftime(datetime, sizeof(datetime), "%d.%m.%Y %H:%M", localTime);

    printf(" LEFA  Build : %s\n", datetime);
}
*/

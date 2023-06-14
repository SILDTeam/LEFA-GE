#include <stdio.h>
#include <time.h>

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
    printf("Failed to initialize GLAD\n");
    }


void vertexERROR()
    {
    printf("Vertex shader compilation failed\n");
    }


void fragERROR()
    {
    printf("Fragment shader compilation failed\n");
    }

    
void shaderLinkERROR()
    {
    printf("Shader program linking failed\n");
    }

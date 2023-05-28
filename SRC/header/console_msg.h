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
    strftime(datetime, sizeof(datetime), "%d/%m/%Y %H:%M", localTime);

    printf("LEFA_GE V:%s\n", datetime);
}

/*void engineCompilation()
{
    // Obtém a data e hora atual
    time_t t = time(NULL);
    struct tm* now = localtime(&t);

    // Formata a data e hora no formato desejado
    char datetimeStr[20];
    strftime(datetimeStr, sizeof(datetimeStr), "%d/%m/%Y %H:%M:%S", now);

    // Imprime a versão e a data/hora de compilação
    printf("LEFA_GE version 0.0.0.5 Compilation :%s\n", datetimeStr);
}*/

//IGNORE
void meme()
{

	printf(" (\\_/)\n"
		   " ( ._.)\n"
		   " / >::<\n"
		   "\n");
}

//void engineCompilation()
//{
//    printf("LEFA_GE V:28/05/2023 \n");
//}

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

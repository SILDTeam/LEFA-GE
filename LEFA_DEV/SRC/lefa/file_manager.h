#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

static void ifGameConfigNotExist(){
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
                        "// Window Config "
                        " "
                         "\n wsize = \"800x600\"; "
                         "\n frameRate =\"60\"; ");
        fclose(usrc);


        printf(" Error! : GC_engine.lec Not found! \n");


    // Se o programa chegou até aqui, houve um erro ao reiniciar o programa
    printf("\nError! : Failed to restart the program.\n\n");


const char* command = "BAZ";

    // Executar o comando para reiniciar o programa
    int result = system(command);

    // Verificar se houve um erro ao reiniciar o programa
    if (result == -1) {
        printf("\nError! : Failed to restart the program.\n\n");
        exit(-1); // Terminar o programa caso não seja possível reiniciá-lo
    }
    exit(0);

}

#endif


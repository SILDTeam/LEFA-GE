/*Open LEFA Project
2022-2023
*/
#include<stdio.h>
#include<unistd.h>;

//SHOW LINUX CONSOLE 

void EnableHUDConsole() {
}

void ShowConsoleWindow() {
    if (isatty(fileno(stdout))) {
        printf("\033[2J"); // Limpar a tela do terminal usando ANSI escape sequence
        fflush(stdout); // Certificar-se de que a saída seja exibida imediatamente
    }
}

/*
void ShowConsoleWindow() {
    if (isatty(fileno(stdout))) {
        system("clear");
    }
}
*/

void HideConsoleWindow() {
    // Não faz nada, já que não há uma janela de console a ser ocultada no Linux
}

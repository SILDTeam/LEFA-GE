
#include <unistd.h>

//SHOW LINUX CONSOLE 

void EnableHUDConsole() {
}


void ShowConsoleWindow() {
    if (isatty(fileno(stdout))) {
        system("clear");
    }
}

void HideConsoleWindow() {
    // Não faz nada, já que não há uma janela de console a ser ocultada no Linux
}
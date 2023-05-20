#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <GL/glut.h>

using namespace std;

int main(int argc, char** argv) {
    FILE* arquivo = fopen("config.txt", "r");

    int width = 0, height = 0;
    char title[100] = {0};

    char linha[100];
    while (fgets(linha, 100, arquivo)) {
        // Ignora linhas vazias ou que começam com '#' ou ';'
        if (linha[0] == '\n' || linha[0] == '#' || linha[0] == ';') {
            continue;
        }

        // Lê a chave e o valor
        char chave[100], valor[100];
        sscanf(linha, "%[^=]=%[^;] ;", chave, valor);

        // Configura a janela de acordo com as chaves e valores
        if (strcmp(chave, "width") == 0) {
            width = atoi(valor);
        } else if (strcmp(chave, "height") == 0) {
            height = atoi(valor);
        } else if (strcmp(chave, "title") == 0) {
            strcpy(title, valor);
        }
    }

    fclose(arquivo);

    // Inicia a janela GLUT com as configurações lidas
    glutInit(&argc, argv);
    glutInitWindowSize(width, height);
    glutCreateWindow(title);

    // Resto do código da sua aplicação

    return 0;
}
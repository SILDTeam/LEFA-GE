#ifndef WINDOW_SYSTEM_HPP
#define WINDOW_SYSTEM_HPP

#include<windows.h>
#include<string.h>

// Função para criar uma janela
void engineCreateWindow(int width, int height);

// Função para definir o título da janela
void engineSetWindowTitle(const char* title);

// Função para definir o ícone da janela
void engineSetWindowIcon(const char* iconPath);

// Função para obter a resolução da janela
void engineGetWindowResolution(int& width, int& height);

int engineGLoop(void (*renderFunction)());

#endif // WINDOW_SYSTEM_HPP




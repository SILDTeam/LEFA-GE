//User Input 
#include"windowSystem.hpp";
#include"uInput.hpp";

#include<windows.h>
#include<stdio.h>
#include<stdbool.h>
#include<iostream.h>

extern HWND hWnd;

bool inputEnabled = true;

//bool isSomethingChanged = false;

extern int windowWidth;
extern int windowHeight;

void processInput()
{

}

void setInputEnabled(bool enabled)
{
    inputEnabled = enabled;
}

bool keyInput(int key)
{
    if (!inputEnabled)
    {
        return false; // Se o processamento das teclas estiver desabilitado, retorna falso
    }

    // Obter o estado do botão usando GetAsyncKeyState
    return GetAsyncKeyState(key) & PRESS_STATE;
}

void mouseInput()
{
    if (inputEnabled)
    {
        // Obter as coordenadas x e y do mouse em relação à tela
        POINT mousePos;
        GetCursorPos(&mousePos);

        // Converter as coordenadas para coordenadas relativas à janela
        ScreenToClient(hWnd, &mousePos);

        RECT windowRect;
    	GetClientRect(hWnd, &windowRect);

    	if (PtInRect(&windowRect, mousePos))
    {
        // O mouse está dentro dos limites da janela
        static int lastMouseX = 0;
        static int lastMouseY = 0;

        if (mousePos.x != lastMouseX || mousePos.y != lastMouseY)
        {
            lastMouseX = mousePos.x;
            lastMouseY = mousePos.y;
            printf("Mouse Pos: x = %d, y = %d\n", lastMouseX, lastMouseY);
        }
       }
    }
}



/*
void mouseInput()
{
    // Obter as coordenadas x e y do mouse em relação à tela
    POINT mousePos;
    GetCursorPos(&mousePos);

    // Converter as coordenadas para coordenadas relativas à janela
    ScreenToClient(hWnd, &mousePos);

    // Verificar se houve movimento do mouse
    static int lastMouseX = 0;
    static int lastMouseY = 0;
    if (mousePos.x != lastMouseX || mousePos.y != lastMouseY)
    {
        lastMouseX = mousePos.x;
        lastMouseY = mousePos.y;
        printf("Mouse Pos: x = %d, y = %d\n", lastMouseX, lastMouseY);
    }
}
*/



/*
void processInput()
{
    if (GetAsyncKeyState(0x1B) & 0x8000)
    {
        printf("Kill_Program! \n");
        exit(0);
    }
    if (keyStates['E'].isPressed) {
        isSomethingChanged = true;
    }
}
*/

/*
void processInput()
{
    MSG msg;
    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {
        if (msg.message == WM_QUIT)
        {
            isRunning = false;
            break;
        }

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Implemente aqui a lógica para processar as teclas pressionadas, movimento do mouse, etc.
    // Por exemplo:
    if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
    {
        isRunning = false;
    }
}
*/

/*


//US

// Letras maiúsculas (A-Z)
0x41   // A
0x42   // B
0x43   // C
0x44   // D
0x45   // E
0x46   // F
0x47   // G
0x48   // H
0x49   // I
0x4A   // J
0x4B   // K
0x4C   // L
0x4D   // M
0x4E   // N
0x4F   // O
0x50   // P
0x51   // Q
0x52   // R
0x53   // S
0x54   // T
0x55   // U
0x56   // V
0x57   // W
0x58   // X
0x59   // Y
0x5A   // Z

// Numbers (0-9)
0x30   // 0
0x31   // 1
0x32   // 2
0x33   // 3
0x34   // 4
0x35   // 5
0x36   // 6
0x37   // 7
0x38   // 8
0x39   // 9

// function keys (F1-F12)
0x70   // F1
0x71   // F2
0x72   // F3
0x73   // F4
0x74   // F5
0x75   // F6
0x76   // F7
0x77   // F8
0x78   // F9
0x79   // F10
0x7A   // F11
0x7B   // F12

// Control Keys
0x08   // Backspace
0x09   // Tab
0x0D   // Enter
0x1B   // Esc

// Arrow Keys
0x25   // <  Seta para a Esquerda
0x26   // /\ Seta para Cima
0x27   // >  Seta para a Direita
0x28   // \/ Seta para Baixo

// KP_keys
0x60   // Teclado Numérico 0
0x61   // Teclado Numérico 1
0x62   // Teclado Numérico 2
0x63   // Teclado Numérico 3
0x64   // Teclado Numérico 4
0x65   // Teclado Numérico 5
0x66   // Teclado Numérico 6
0x67   // Teclado Numérico 7
0x68   // Teclado Numérico 8
0x69   // Teclado Numérico 9
0x6A   // Teclado Numérico Asterisco (*)
0x6B   // Teclado Numérico Mais (+)
0x6D   // Teclado Numérico Menos (-)
0x6E   // Teclado Numérico Ponto Decimal (.)
0x6F   // Teclado Numérico Dividir (/)

// Outras teclas especiais
0x20   // Space
0x2D   // Insert
0x2E   // Delete
*/


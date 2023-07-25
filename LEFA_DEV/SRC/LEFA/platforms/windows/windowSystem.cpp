#include"windowSystem.hpp";
#include"uInput.hpp";
//
#include<windows.h>
#include<GL/GL.H>
#include<cstdio>


HWND hWnd; // Manipulador da janela
HDC hdc;
HGLRC hrc;

bool isRunning = true;
const char* className = "lefaWClass";

bool isWindowBorderless = false;

bool isWindowActive = true; // Variável para controlar se a janela do jogo está ativa ou não
int windowWidth;
int windowHeight;


LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    // Processar mensagens da janela
    switch (uMsg)
    {

        case WM_SIZE:
        {
            // Atualizar as variáveis globais com a largura e altura da janela
            windowWidth = LOWORD(lParam);
            windowHeight = HIWORD(lParam);
            break;
        }

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}



void engineCreateWindow(int width, int height)
{   
    //Register the window class
    HINSTANCE hInstance = GetModuleHandle(NULL);

    WNDCLASS wc = {0};

    wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.lpszMenuName = NULL;

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = className;
    //RegisterClass(&wc);

    if (!RegisterClass(&wc))
        exit(1);


    //Get screen dimensions
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
     //Calculate window coordinates to center it on the screen
    int windowPosX = (screenWidth - width) / 2;
    int windowPosY = (screenHeight - height) / 2;

    // Criar a janela
    hWnd = CreateWindowEx(
        0,
        className,
        "LEFA_Engine",
        WS_OVERLAPPEDWINDOW,
        windowPosX,           //window PosX
        windowPosY,           //window PosY
        width,                //window Width
        height,               //window Height
        NULL,
        NULL,
        wc.hInstance,
        NULL);


    if (hWnd == NULL)
        exit(0);

    hdc = GetDC(hWnd);

    PIXELFORMATDESCRIPTOR pfd;
    ZeroMemory(&pfd, sizeof(pfd));
    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cDepthBits = 24;
    pfd.cStencilBits = 8;
    pfd.iLayerType = PFD_MAIN_PLANE;

    int pixelFormat = ChoosePixelFormat(hdc, &pfd);
    SetPixelFormat(hdc, pixelFormat, &pfd);

    hrc = wglCreateContext(hdc);
    wglMakeCurrent(hdc, hrc);

    // Mostrar a janela
    ShowWindow(hWnd, SW_SHOWDEFAULT);
}


int runEngineLoop(void (*renderFunction)())
{

    //Start Loop
    MSG msg;
    while (isRunning) // Loop será executado enquanto isRunning for true
    {
        //check if the window is active
        isWindowActive = (GetForegroundWindow() == hWnd);

         setInputEnabled(isWindowActive);

        if (isWindowActive)
        {
            mouseInput();
        }



        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                isRunning = false; //Set isRunning to false to end the loop
                break;
            }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        renderFunction();
        SwapBuffers(hdc);
    }
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hrc);
    ReleaseDC(hWnd, hdc);
    DestroyWindow(hWnd);

    return (int)msg.wParam;
}


void engineSetWindowTitle(const char* title)
{
    //Set window title
    SetWindowText(hWnd, title);
}

void engineSetWindowIcon(const char* iconPath)
{
    //Set the window icon
    HICON hIcon = (HICON)LoadImage(
        GetModuleHandle(NULL),
        iconPath,
        IMAGE_ICON,
        32,
        32,
        LR_LOADFROMFILE);
    SendMessage(hWnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
}




void windowBorderless(int windowWidth, int windowHeight)
{
    if (isWindowBorderless) {
        // Se já está sem bordas, restaura o estilo da janela com bordas
        DWORD style = GetWindowLongPtr(hWnd, GWL_STYLE);
        style |= (WS_CAPTION | WS_THICKFRAME);
        SetWindowLongPtr(hWnd, GWL_STYLE, style);
        SetWindowPos(hWnd, HWND_TOP,
                     0, 0,
                     windowWidth, windowHeight,
                     SWP_SHOWWINDOW | SWP_FRAMECHANGED);

        isWindowBorderless = false;
    }
    else {
        // Se está com bordas, remove as bordas e define o tamanho e posição da janela para ocupar toda a tela
        DWORD style = GetWindowLongPtr(hWnd, GWL_STYLE);
        style &= ~(WS_CAPTION | WS_THICKFRAME);
        SetWindowLongPtr(hWnd, GWL_STYLE, style);
        SetWindowPos(hWnd, HWND_TOP,
                     0, 0,
                     GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN),
                     SWP_SHOWWINDOW | SWP_FRAMECHANGED);

        isWindowBorderless = true;
    }
}

/*
void windowBorderless()
{
    // Obter o estilo atual da janela
    DWORD style = GetWindowLongPtr(hWnd, GWL_STYLE);

    // Remover bordas e definir o tamanho e posição da janela para ocupar toda a tela
    SetWindowLongPtr(hWnd, GWL_STYLE, style & ~(WS_CAPTION | WS_THICKFRAME));
    SetWindowPos(hWnd, HWND_TOP,
                 0, 0,
                 GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN),
                 SWP_NOOWNERZORDER | SWP_FRAMECHANGED);
}
*/



/* is a broke func
void enigneGetWindowResolution(int& width, int& height)
{
    // Obter a resolução da janela
    RECT rect;
    GetClientRect(hWnd, &rect);
    width = rect.right - rect.left;
    height = rect.bottom - rect.top;
}
*/

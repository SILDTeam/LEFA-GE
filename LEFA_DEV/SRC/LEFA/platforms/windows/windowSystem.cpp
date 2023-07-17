#include"windowSystem.hpp";
#include<windows.h>
#include<GL/GL.H>


HWND hWnd; // Manipulador da janela
HDC hdc;
HGLRC hrc;

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    // Processar mensagens da janela
    switch (uMsg)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}


void engineCreateWindow(int width, int height)
{   
    // Registrar a classe da janela
    const char* className = "lefaWClass";
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


    // Obter as dimensões da tela
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
     // Calcular as coordenadas da janela para centralizá-la na tela
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

int engineGLoop(void (*renderFunction)())
{
    // Restante do código...

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

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
    // Definir o título da janela
    SetWindowText(hWnd, title);
}

void engineSetWindowIcon(const char* iconPath)
{
    // Definir o ícone da janela
    HICON hIcon = (HICON)LoadImage(
        GetModuleHandle(NULL),
        iconPath,
        IMAGE_ICON,
        32,
        32,
        LR_LOADFROMFILE);
    SendMessage(hWnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
}

void enigneGetWindowResolution(int& width, int& height)
{
    // Obter a resolução da janela
    RECT rect;
    GetClientRect(hWnd, &rect);
    width = rect.right - rect.left;
    height = rect.bottom - rect.top;
}

/*
bool engineWindowShouldClose()
{
    MSG msg;
    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {
        if (msg.message == WM_QUIT)
            return true;

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return false;
}
*/


/*
HWND hWnd; // Manipulador da janela

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    // Processar mensagens da janela
    switch (uMsg)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void engineCreateWindow(int width, int height)
{
    // Registrar a classe da janela
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "GameEngineWindowClass";
    RegisterClass(&wc);

    // Criar a janela
    hWnd = CreateWindowEx(
        0,
        "GameEngineWindowClass",
        "Game Engine",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        width,
        height,
        NULL,
        NULL,
        wc.hInstance,
        NULL);

    // Mostrar a janela
    ShowWindow(hWnd, SW_SHOWDEFAULT);
}

void engineSetWindowIcon(const char* iconPath)
{
    // Definir o ícone da janela
    HICON hIcon = (HICON)LoadImage(
        GetModuleHandle(NULL),
        iconPath,
        IMAGE_ICON,
        32,
        32,
        LR_LOADFROMFILE);
    SendMessage(hWnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);
}

void engineSetWindowTitle(const char* title)
{
    // Definir o título da janela
    SetWindowText(hWnd, title);
}
*/
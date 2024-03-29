#include"lefa/engineArgs.h"

#ifdef _WIN32
    #include<windows.h>
    //Resource Script
    #include"lefa/platforms/windows_header.h";
#endif

#ifdef _LINUX
    #include<dlfcn.h>
    #include"lefa/platforms/linux_header.h";
#endif

//#include<cstring> // strcmp for new Compilers . Open Watcom need windows.h for load strcmp

void ToggleConsoleWindow(int argc, char** argv)
{
    if (argc > 1 && strcmp(argv[1], "-sw_console") == 0) {
        ShowConsoleWindow();
    } else {
        HideConsoleWindow();
    }
}



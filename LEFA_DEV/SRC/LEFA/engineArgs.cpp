#include"engineArgs.h"

#ifdef WIN32
    #include<windows.h>
    //Resource Script
    #include"platforms/windows_header.h";
#endif

#ifdef LINUX
    #include<dlfcn.h>
    #include"platforms/linux_header.h";
    #include<string.h>
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

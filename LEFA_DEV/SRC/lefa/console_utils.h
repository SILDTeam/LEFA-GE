#include<stdio.h>
//#include<stdarg.h>
#include<time.h>
#include<string.h>




//ANSI Colors dont work with WATCOM_C
#define ANSI_COLOR_RED     "\x1b[31m" 
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

static inline void printERR(const char *errorMsg) {

    printf("ERROR! : %s\n", errorMsg);

}




static void printLine(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    printf("\n");
    va_end(args);
}


static void gameVersion(const char* gameName, const char* version)
{
    printLine("%s / %s", gameName, version);
}

static void engineVersion()
{
    printLine("LEFA Build: 29.09.23");
}



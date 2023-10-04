@echo off
title Program Build! |color 06
echo """"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
echo "                                                                                     "
echo "               ______                                                                "
echo "             _/      /                                                               "
echo "     _______|        /________                                                       "
echo "   _/       |        /__     |                                                       "
echo "   \        |          /     |                                                       "
echo "    \       |___     /       |                                                       "
echo "     \         /    /        |                                                       "
echo "      \       /    /_        |                                                       "
echo "       \     |__/   _        |                                                       "
echo "        \______/  //_________|                                                       "
echo "              / /                                                                    "
echo "             //                                                                      "
echo "                                                                                     "
echo "                                                                                     "
echo """""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
echo.
echo.

REM setlocal enabledelayedexpansion  REM delayed variable expansion / Problem Disable ! char


REM IGNORE COMMAND  2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"

REM /6r (32-bit only) generate 386 instructions based on Intel Pentium Pro instruction timings and
REM   use register-based argument passing conventions

REM /6s (32-bit only) generate 386 instructions based on Intel Pentium Pro instruction timings and
REM   use stack-based argument passing conventions

REM -fp6 Optimized Option For Binary Precision / generate in-line 80x87 instructions optimized for Pentium Pro processor
REM -et Get Debug Functions()

REM SET DIR_LEFA=lefa
SET DIR_GAME=lefaDemos/
SET DIR_OUTPUT=lefaDEMO/
REM program object , and build files.
SET EXIT=../%DIR_OUTPUT%/obj
SET buildout=../
SET exename=poly

for /r "%DIR_OUTPUT%/obj" %%f in (*.obj) do del "%%f"


REM Create DIR
REM _________________________________________
if not exist "%DIR_OUTPUT%" (
    mkdir "%DIR_OUTPUT%"
    echo Direcorty '%DIR_OUTPUT%'created with sucess.
) else (
    echo.
)
REM _________________________________________
REM _________________________________________
if not exist "%DIR_OUTPUT%/obj" (
    mkdir "%DIR_OUTPUT%/obj"
    echo Direcorty '%DIR_OUTPUT%/obj'created with sucess.
) else (
    echo.
)
REM _________________________________________


REM Time /t >  build_out.txt
REM Date /t >> build_out.txt
REM echo last_compilation >> build_out.txt



REM Define Compiler. 
REM WATCOM 1.9
REM ______________________________
REM I386+
set cc=wcc386
set cpp=wpp386

REM SILD WATCOM 0.0 test
REM AMD64 / EM64t
REM set cc=wcc64  REM tests
REM set cpp=wpp64 REM tests

REM ______________________________


cd SRC
echo.
echo Demo or game Source
echo ___________________________________________________________________________________________________________________
echo.
echo  __________(windowPoly.CPP)________________________________________
echo /____________________________________________________________\
 	 @%cpp% -DWIN32 /6r -fp6 lefaDemos/windowPoly.cpp -Fo="%EXIT%/main"  ^
     2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"
echo ______________________________________________________________
echo \____________________________________________________________/
echo.
echo.
echo.
echo.
echo """""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
echo " Engine Files                                                                                                        "
echo """"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""/
echo.
echo  _________WINDOWSYSTEM.C____________________________________
echo /____________________________________________________________\
     @%cpp% /6r -fp6 -ol -oo "lefa/platforms/windows/windowSystem.c" -Fo="%EXIT%/windowSystem" ^
     2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"
echo ______________________________________________________________
echo \____________________________________________________________/
echo.
echo.
echo.
echo  ____________UINPUT.C______________________________________
echo /____________________________________________________________\
     @%cpp% /6r -fp6 -ol -oo "lefa/platforms/windows/uInput.c" -Fo="%EXIT%/uInput" ^
     2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"
echo ______________________________________________________________
echo \____________________________________________________________/
echo.
echo.
echo.
echo.
echo  ____________CUSTOMCUR.C_____________________________________
echo /____________________________________________________________\
      @%cpp% /6r -fp6 -ol -oo "lefa/platforms/windows/customCur.c" -Fo="%EXIT%/customCur" ^
      2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"
echo ______________________________________________________________
echo \____________________________________________________________/
echo.
echo.
echo.
echo  __________ENGINEARGS.C______________________________________
echo /____________________________________________________________\
     @%cpp% -D_WIN32 /6r -oo -ol -fp6 "lefa/Extension/engineArgs.c" -Fo="%EXIT%/engineArgs" ^
     2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"
echo ______________________________________________________________
echo \____________________________________________________________/
echo.
echo.
echo.
echo.
echo.
echo.
echo  ___________GLAD_GL.C________________________________________
echo /____________________________________________________________\
     @%cpp% /6r -fp6 -ol -oo "lefa/ThirdParty/glad/OpenGL/glad_gl.c" -Fo="%EXIT%/glad_gl" ^
     2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"
echo ______________________________________________________________
echo \____________________________________________________________/
echo.
echo.
echo.
echo.
echo.
echo  __________(RESOURCE)________________________________________
echo /____________________________________________________________\
     @wrc lefaDemos/resources/win32.rc -r -fo="%EXIT%/win32.res"   ^
     2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"
echo ______________________________________________________________
echo \____________________________________________________________/
echo.
echo.
echo.
cd ../
cd %DIR_OUTPUT%/obj
echo.
echo.
echo  __________(Linker)________________________________________
echo /__________________________________________________________\
     @wlink option resource 'win32.res' name %exename%.exe file *.obj ^
     2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"
echo ____________________________________________________________
echo \__________________________________________________________/

REM move the bin file system
REM _________________________________________
if exist *.exe (
    move *.exe "%buildout%" | echo DONE !
) else (
    echo BUILD FAIL !
)
REM _________________________________________


echo.
echo _


pause

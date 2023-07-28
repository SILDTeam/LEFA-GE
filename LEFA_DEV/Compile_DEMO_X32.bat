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

setlocal enabledelayedexpansion

REM LEFA Window Demo

REM IGNORE COMMAND  2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"

REM /6r (32-bit only) generate 386 instructions based on Intel Pentium Pro instruction timings and
REM   use register-based argument passing conventions

REM /6s (32-bit only) generate 386 instructions based on Intel Pentium Pro instruction timings and
REM   use stack-based argument passing conventions

REM -fp6 Optimized Option For Binary Precision / generate in-line 80x87 instructions optimized for Pentium Pro processor
REM -et Get Debug Functions()


if not exist "EXT" (
    mkdir "EXT"
    echo Direcorty 'EXT'created with sucess.
) else (
    echo.
)

Time /t > build_out.txt
Date /t >> build_out.txt
echo last_compilation >> build_out.txt


cd src
echo.
echo Demo or game Source
echo ___________________________________________________________________________________________________________________
echo.
echo  __________(windowPoly.CPP)________________________________________
echo /____________________________________________________________\
 	 @wpp386 -DWIN32 /6r -fp6 lefaDemos/windowPoly.cpp -Fo="../EXT/main"  ^
     2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"
echo ______________________________________________________________
echo \____________________________________________________________/
echo.
echo.
echo.
echo  __________(WINDOWSYSTEM.CPP)__________________________________
echo /____________________________________________________________\
     @wpp386 /6r -fp6 lefa/platforms/windows/windowSystem.cpp -Fo="../EXT/windowSystem" ^
     2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"
echo ______________________________________________________________
echo \____________________________________________________________/
echo.
echo.
echo.
echo.
echo Engine Files
echo _______________________________________________________________________________________________________________________
echo.
echo  __________(WINDOWSYSTEM.CPP)__________________________________
echo /____________________________________________________________\
     @wpp386 /6r -fp6 -et lefa/platforms/windows/windowSystem.cpp -Fo="../EXT/windowSystem" ^
     2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"
echo ______________________________________________________________
echo \____________________________________________________________/
echo.
echo.
echo.
echo.
echo.
echo.
echo  __________(UINPUT.CPP)__________________________________
echo /____________________________________________________________\
     @wpp386 /6r -fp6 -et lefa/platforms/windows/uInput.cpp -Fo="../EXT/uInput" ^
     2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"
echo ______________________________________________________________
echo \____________________________________________________________/
echo.
echo.
echo.
echo.
echo.
echo  __________(engineArgs.CPP)__________________________________
echo /____________________________________________________________\
     @wpp386 -DWIN32 /6r -fp6 lefa/engineArgs.cpp -Fo="../EXT/engineArgs" ^
     2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"
echo ______________________________________________________________
echo \____________________________________________________________/
echo.
echo.
echo.
echo.
echo.
echo  __________(GLAD_GL.C)__________________________________________
echo /____________________________________________________________\
     @wpp386 /6r lefa/render/glad/GLAD_GL.C -fp6 -Fo="../EXT/glad" ^
     2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"
echo ______________________________________________________________
echo \____________________________________________________________/
echo.
echo.
echo.
echo  __________(RESOURCE)________________________________________
echo /____________________________________________________________\
     @wrc lefaDemos/resources/win32.rc -r -fo="../EXT/win32.res"   ^
     2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"
echo ______________________________________________________________
echo \____________________________________________________________/
echo.
echo.
echo.
cd ../
cd EXT
echo.
echo.
echo  __________(Linker)________________________________________
echo /__________________________________________________________\
     @wlink option resource 'win32.res' name LEFA.exe file *.obj ^
     2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"
echo ____________________________________________________________
echo \__________________________________________________________/


	REM wpp386 main.cpp -i="c:\WATCOM19/h;c:\WATCOM19/h/nt" -w4-e25 -zq -od-d2 -6r -bt=nt -fo=obj -mf-xs -xr
	REM wrc res.rc -bt=nt -dWIN32 -d_WIN32 -d__NT__ -i=";C:\WATCOM19/h;C:WATCOM19/h/nt"-q -ad -r -fo=res.res
	REM wlink name lefa_test d all sys nt_win op m op maxe=25 op q op symf main
echo.
echo _

del *.obj 
del *.res 

pause

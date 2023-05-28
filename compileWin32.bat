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
Time /t
Date /t
echo.

REM IGNORE 2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"  COMMAND

REM /6s Optimized Option For Pentium x32 family (Pentium Pro | Pentium II)

if not exist "EXT" (
    REM Criar o diretório "EXT"
    mkdir "EXT"
    echo Direcorty 'EXT'created with sucess.
) else (
    echo.
)

REM MKDIR EXT
cd src
echo.
echo  __________(MAIN.CPP)________________________________________
echo /____________________________________________________________\
 	 @wpp386 -DWINDOWS /6s main.cpp -Fo="../EXT/main" ^
 	 2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"
echo ______________________________________________________________
echo \____________________________________________________________/
echo.
echo.
echo.
echo.
echo  __________(GLAD.C)__________________________________________
echo /____________________________________________________________\
 	 @wpp386 /6s glad.c -Fo="../EXT/glad" ^
 	 2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"
echo ______________________________________________________________
echo \____________________________________________________________/
echo.
echo.
echo.
echo  __________(RESOURCE)________________________________________
echo /____________________________________________________________\
	 @wrc win32.rc -r -fo="../EXT/win32.res" -i="$[:;C:\WATCOM19/h;C:\W&ATCOM19/h/nt" ^
	 2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"
echo ______________________________________________________________
echo \____________________________________________________________/
echo.
echo.
cd ../
cd EXT
echo.
echo.
echo  __________(Linker)________________________________________
echo /__________________________________________________________\
     @wlink option resource 'win32.res' name BAZ.exe file *.obj  ^
     2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"
echo ____________________________________________________________
echo \__________________________________________________________/


	REM wpp386 main.cpp -i="c:\WATCOM19/h;c:\WATCOM19/h/nt" -w4-e25 -zq -od-d2 -6r -bt=nt -fo=obj -mf-xs -xr
	REM wrc res.rc -bt=nt -dWIN32 -d_WIN32 -d__NT__ -i=";C:\WATCOM19/h;C:WATCOM19/h/nt"-q -ad -r -fo=res.res
	REM wlink name lefa_test d all sys nt_win op m op maxe=25 op q op symf main
echo.
echo _
pause
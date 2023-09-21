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

REM Time /t >  build_out.txt
REM Date /t >> build_out.txt
REM echo last_compilation >> build_out.txt

SET EXIT=../EXT/


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


cd src
echo.
echo Demo or game Source
echo ___________________________________________________________________________________________________________________
echo.
echo  __________(windowPoly.CPP)________________________________________
echo /____________________________________________________________\
 	 @%cpp% -DWIN32 /6r -fp6 lefaDemos/windowPoly.cpp -Fo="../EXT/main"  ^
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
echo  _________WINDOWSYSTEM.CPP___________________________________
echo /____________________________________________________________\
     @%cpp% /6r -fp6 -ol -oo -et lefa/platforms/windows/windowSystem.cpp -Fo="%EXIT%/windowSystem" ^
     2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"
echo ______________________________________________________________
echo \____________________________________________________________/
echo.
echo.
echo.
echo  ____________UINPUT.CPP______________________________________
echo /____________________________________________________________\
     @%cpp% /6r -fp6 -ol -oo -et lefa/platforms/windows/uInput.cpp -Fo="%EXIT%/uInput" ^
     2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"
echo ______________________________________________________________
echo \____________________________________________________________/
echo.
echo.
echo.
echo.
echo  ____________CUSTOMCUR.C_____________________________________
echo /____________________________________________________________\
      @%cpp% /6r -fp6 -ol -oo -et lefa/platforms/windows/customCur.c -Fo="%EXIT%/customCur" ^
      2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"
echo ______________________________________________________________
echo \____________________________________________________________/
echo.
echo.
echo.
echo  __________ENGINEARGS.C______________________________________
echo /____________________________________________________________\
     @%cpp% -DWIN32 /6r -oo -fp6 -et lefa/Extension/engineArgs.c -Fo="%EXIT%/engineArgs" ^
     2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"
echo ______________________________________________________________
echo \____________________________________________________________/
echo.
echo.
echo.
echo.
echo.
echo.
echo  ___________MATRIX44.C________________________________________
echo /____________________________________________________________\
     @%cpp% /6r lefa/Math/Matrix44.c -fp6 -ol -oo -et -Fo="%EXIT%/Matrix44" ^
     2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"
echo ______________________________________________________________
echo \____________________________________________________________/
echo.
echo.
echo.
echo.
echo.
echo.
echo.
echo  ___________VECTOR2.C________________________________________
echo /____________________________________________________________\
     @%cpp% /6r lefa/Math/Vector2.c -fp6 -ol -oo -et -Fo="%EXIT%/Vector2" ^
     2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"
echo ______________________________________________________________
echo \____________________________________________________________/
echo.
echo.
echo.
echo.
echo.
echo  ___________VECTOR3.C________________________________________
echo /____________________________________________________________\
     @%cpp% /6r lefa/Math/Vector3.c -fp6 -ol -oo -et -Fo="%EXIT%/Vector3" ^
     2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"
echo ______________________________________________________________
echo \____________________________________________________________/
echo.
echo.
echo.
echo.
echo.
echo.
echo  ___________TRANSFORM.C______________________________________
echo /____________________________________________________________\
     @%cpp% /6r lefa/Math/Transform.c -fp6 -ol -oo -et -Fo="%EXIT%/Transform" ^
     2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"
echo ______________________________________________________________
echo \____________________________________________________________/
echo.
echo.
echo.
echo.
echo.
echo.
echo  ___________QUATERNION.C_____________________________________
echo /____________________________________________________________\
     @%cpp% /6r lefa/Math/Quaternion.c -fp6 -ol -oo -et -Fo="%EXIT%/Quaternion" ^
     2>&1 | findstr /V /C:"Open Watcom" /C:"Portions" /C:"See"
echo ______________________________________________________________
echo \____________________________________________________________/
echo.
echo.
echo.
echo.
echo.
echo.
echo.
echo  ___________GLAD_GL.C________________________________________
echo /____________________________________________________________\
     @%cpp% /6r lefa/render/OpenGL/GLAD_GL.C -fp6 -ol -oo -et -Fo="%EXIT%/glad" ^
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

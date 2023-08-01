#!/bin/bash

echo ""
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
echo ""
echo ""
echo ""

mkdir -p "EXT"
echo "Directory 'EXT' created with success."

date > build_out_LINUX.txt
echo "last_compilation" >> build_out_LINUX.txt

cd SRC
echo ""
echo "Demo or game Source"
echo "___________________________________________________________________________________________________________________"
echo ""
echo "  __________(windowPoly.CPP)________________________________________"
echo "/____________________________________________________________\\"
	wpp386 -DLINUX -6r -fp6 "lefaDemos/windowPoly.cpp" -Fo="../EXT/main" \
	2>&1 | grep -v "Open Watcom\|Portions\|See"
echo "________________________________________________________________"
echo "\\____________________________________________________________/"
echo ""
echo ""
echo ""
echo "Engine Files"
echo "_____________________________________________________________________________________________________________________"
echo ""
echo "  __________(WINDOWSYSTEM.CPP)__________________________________"
echo "/____________________________________________________________\\"
	wpp386 -6r -fp6 -et LEFA/platforms/linux/windowSystem.cpp -Fo="../EXT/windowSystem" \
	2>&1 | grep -v "Open Watcom\|Portions\|See"
echo "________________________________________________________________"
echo "\\____________________________________________________________/"
echo ""
echo ""
echo ""
echo ""
echo ""
echo ""
#echo "  __________(UINPUT.CPP)__________________________________"
#echo "/____________________________________________________________\\"
#	wpp386 -6r -fp6 -et LEFA/platforms/linux/uInput.cpp -Fo="../EXT/uInput" 2>&1 | grep -v "Open Watcom\|Portions\|See"
#echo "________________________________________________________________"
#echo "\\____________________________________________________________/"
#echo ""
echo ""
echo ""
echo ""
echo ""
echo "  __________(engineArgs.CPP)__________________________________"
echo "/____________________________________________________________\\"
	wpp386 -DLINUX -6r -fp6 LEFA/engineArgs.cpp -Fo="../EXT/engineArgs" \
	2>&1 | grep -v "Open Watcom\|Portions\|See"
echo "________________________________________________________________"
echo "\\____________________________________________________________/"
echo ""
echo ""
echo ""
echo ""
echo ""
echo "  __________(GLAD_GL.C)__________________________________________"
echo "/____________________________________________________________\\"
	wpp386  -6r LEFA/render/glad/glad_gl.c -fp6 -Fo="../EXT/glad"   \
	2>&1 | grep -v "Open Watcom\|Portions\|See"
echo "________________________________________________________________"
echo "\\____________________________________________________________/"
echo ""
echo ""
echo ""
echo ""
echo For LINUX
echo "  __________(GLAD_GLX.C)__________________________________________"
echo "/____________________________________________________________\\"
	wpp386  -6r LEFA/render/glad/glad_glx.c -fp6 -Fo="../EXT/glad_glx"  \
	2>&1 | grep -v "Open Watcom\|Portions\|See"
echo "________________________________________________________________"
echo "\\____________________________________________________________/"
echo ""
echo ""

#echo ""
#echo "  __________(RESOURCE)________________________________________"
#echo "/____________________________________________________________\\"
#	wrc lefaDemos/resources/win32.rc -r -fo="../EXT/win32.res" 2>&1 | grep -v "Open Watcom\|Portions\|See"
#echo "________________________________________________________________"
#echo "\\____________________________________________________________/"
#echo ""
#echo ""
#echo ""

cd ../EXT
echo ""
echo ""
echo "  __________(Linker)________________________________________"
echo "/__________________________________________________________\\"
	wlink option quiet name LEFA file *.o \
	library /lib/x86_64-linux-gnu/libX11.a \
	library /lib/x86_64-linux-gnu/libGL.a  \
	library /lib/x86_64-linux-gnu/libGLU.a \
	2>&1 | grep -v "Open Watcom\|Portions\|See"
echo "________________________________________________________________"
echo "\\__________________________________________________________/"

# REM wpp386 main.cpp -i="c:\WATCOM19/h;c:\WATCOM19/h/nt" -w4-e25 -zq -od-d2 -6r -bt=nt -fo=obj -mf-xs -xr
# REM wrc res.rc -bt=nt -dWIN32 -d_WIN32 -d__NT__ -i=";C:\WATCOM19/h;C:WATCOM19/h/nt"-q -ad -r -fo=res.res
# REM wlink name lefa_test d all sys nt_win op m op maxe=25 op q op symf main

echo ""
echo "_"

rm -f *.o
#rm -f *.res
cd ..

read -p "Press Enter to continue..."


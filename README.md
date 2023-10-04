DD.MM.YY   
code Version ``04.10.23``  

</div>
  <details>
   <summary> latest changes </summary>  
    
03/10/23 and 04/10/23  
much of the code was changed to support C89, now the window system, input system, cursor system can be included using C89  
added glad_vulkan so that Vulkan API can be included in the project in the future  
    
</details>


##  <img src="web_Help_Res/LEFA_LOGO.png" width="40" height="40" />  LITHE ENGINE FOR ALL  

<img src="web_Help_Res/Troll Face.ico" width="35" height="35" />yes, it's another render being developed in this world, and to make matters worse being created with limitations.

##### Basic Info  

This project is being done by a beginner programmer, who has never had experience in game programming before.   

this code is just the beginning/studies/research of what this could be in the future  
the code is totally poorly optimized

The advancement of the engine and the features in it are added according to what I need.  

example :  if I need fast loading of textures, this is an addition to the engine  

and also, a lot of things are undocumented and lacking in explanation.  

_______

## thank you for third party libraries  

[GLAD](https://github.com/Dav1dde/glad)  as the best loader of khronos libraries  

[LODEPNG](https://github.com/lvandeve/lodepng)  as a great encoder and decoder  

[HYPATIA](https://github.com/dagostinelli/hypatia) mathematical library that I'm still studying, but it looks great

_______

### Requirements to compile or run


System   
Listed here are systems I tested the program on  

Windows :  
  
_  Windows XP SP3  x32  worked correctly  
_  Windows 11 Home x64  worked correctly  

Linux  
_  Debian 12  x64  did not work, there were linking errors with X11  
  ______________ 

CPU  
 Minimum  
  I386 with SSE2 or Higher
 
Recommended  
  I686 = Intel P6 with SSE2 - or Higher  
  
 due to the 6r optimization option, optimization for processors such as Pentium PRO or higher  

___________

RAM  
  Basic Engine  
  windows XP : 4 MB   
  windows 11 : 21 MB  

___________
DISC   
 the code is very small, of course there is very little, for now  
500 kb Disc for source code   

_____
Render  
OpenGL 2.1 or Higher  

____

Even though the code is poorly optimized it is acting well, the problem is the cpu consumption due to the loop and the lack of control over the FPS limit  
the loop is acting at its full power without any limiter making it consume more cpu than it should  


## what you need, to build.
the code is being written in | C 89 and C++ 98  
  
#### to compile you need  

 <img src="web_Help_Res/Watcom_mini.png" width="35" height="35" /> Open Watcom 1.9  
#### Open Watcom Downloads  

- [<img src="web_Help_Res/windows_icon_aero.png" width="25" height="25" /> open-watcom-c-win32-1.9.exe](http://openwatcom.org/ftp/install/open-watcom-c-win32-1.9.exe)   

    
- <img src="web_Help_Res/icons8-linux-96.png" width="25" height="25" />  [open-watcom-c-linux-1.9](http://openwatcom.org/ftp/install/open-watcom-c-linux-1.9)

________

### Windows after Install
</div>
  <details>
   <summary> FOR WINDOWS </summary>  
    
### Fixe watcom OpenGL Syntax Error! 
put OpenGl Modified / Fixed Files Incluse in [more_Files/Windows](https://github.com/SILDTeam/LEFA-GE/tree/main/more_files/windows)  

  replace default WATCOM files  
you need to place the files from the ```more_Files/windows``` directory  inside the Open Watcom installation location  
the default location is ``C:\WATCOM``  
    
</details>








### Install Watcom and Configure Project for linux.
</div>
  <details>
   <summary> FOR LINUX  </summary>  
    
# NOTE ! 
I am using Debian 12 , in case you are using another linux distribution , use some things as base

### step 1


you need to extract `open-watcom-c-linux-1.9` file  
with unzip .

you need to install unzip or something of your choice, but here is unzip.  

##### Unzip Installation 
```sh
sudo apt-get install unzip
```

in the directory where you downloaded the file `open-watcom-c-linux-1.9` put the following command  
```sh
unzip open-watcom-c-linux-1.9 -d WATCOM
```
and will extract the files to the directory called ``WATCOM``   

after this process it is necessary to move this directory to   

`` /usr/bin ``  
with administrator permissions, move the ``WATCOM`` directory to getting like this ` /usr/bin/WATCOM `   

### step 2  

```sh
nano ~/.bashrc
```

you need a script and define Watcom Files path to linux put the code in `.bashrc `   
and now put the entire code below inside the .bashrc file, open the .bashrc and at the end of it put the following code.

```sh
# Open Watcom 1.9 Path Script:
# ---------------------------------------------------------------------------
export WATCOM=/usr/bin/WATCOM
export PATH=$WATCOM/binl:$PATH
export EDPATH=$WATCOM/eddat
export INCLUDE=$WATCOM/lh
export LIB=$WATCOM/libl
# ---------------------------------------------------------------------------
```  
after this , get WATCOM dir ADMIN .

```sh
sudo chmod -R 777 /usr/bin/WATCOM
```
----

## X11 LIBs

Just Wait

##### NOTE ! libX11.a is not working in Open Watcom 1.9 , we need Compile libX11.a with Open Watcom .

</details>

________



 



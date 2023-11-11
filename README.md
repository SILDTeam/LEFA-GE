DD.MM.YY   
code Version ``04.10.23``  

</div>
  <details>
   <summary> latest changes </summary>  
    
```03/10/23``` and ```04/10/23```  
much of the code was changed to support C89, now the window system, input system, cursor system can be included using C89  
added glad_vulkan so that Vulkan API can be included in the project in the future  
    
</details>


##  <img src="web_Help_Res/LEFA_LOGO.png" width="40" height="40" />  LITHE ENGINE FOR ALL  

### platform support

<p align="left">
  <a href="link_for_windows_os_doc">
    <img src="https://cdn.icon-icons.com/icons2/5/PNG/256/windows_284.png" alt="windows_ico" width="50" height="50">
  </a>
  100% ⅃     
  <a href="link_for_linux_os_doc">
    <img src="https://icons.iconarchive.com/icons/kearone/comicons/128/linux-icon.png" alt="linux_ico" width="50" height="50">
  </a>
  13% ⅃ 
  <a href="link_for_BSD_os_doc">
    <img src="https://img.icons8.com/?size=256&id=17840&format=png" alt="BSD_ico" width="50" height="50">
  </a>
  0% ⅃ 
</p>

***

##### Basic Info  

<img src="web_Help_Res/Troll Face.ico" width="35" height="35" />yes, it's another render being developed in this world, and to make matters worse being created with limitations.


This project is being done by a beginner programmer, who has never had experience in game programming before.   

this code is just the beginning/studies/research of what this could be in the future  
the code is totally poorly optimized

The advancement of the engine and the features in it are added according to what I need.  

example :  if I need fast loading of textures, this is an addition to the engine  

and also, a lot of things are undocumented and lacking in explanation.  

_______

## thank you ! third-party libraries

[GLAD](https://github.com/Dav1dde/glad)  as the best loader of khronos libraries  

[LODEPNG](https://github.com/lvandeve/lodepng)  as a great PNG encoder and decoder  

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
  ``I686`` = Intel P6 with SSE2 - or Higher  
  
 I recommend not trying to compile for ``i386``, since these processors are much older and out of date, the x32 base computers for the engine are those with ``i686`` or higher as they are much more optimized for calculations and their cores and shifts are faster .    


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


## Problems  
- Even though the code is poorly optimized it is acting well, the problem is the cpu consumption due to the loop and the lack of control over the FPS limit  
the loop is acting at its full power without any limiter making it consume more cpu than it should  

- Inconsistent changes to the project without a defined structure  

- project being done by just one person, and still being new to coding  

- the project does not contain makefile systems, I don't like make but using other compilers instead of watcom is a pain  

- Currently, configuring the project for different architectures is horrible, and for different systems it is moderately smooth.  

- still stuck in the initial development process for 9 months  

- poorly organized file names and no creation  

________

## good side 

- is being written in C89 (ANSI C)  

- It seems to be very compatible with some different systems.  

- The purpose is to be light and portable  

- opens on my grandmother's computer, except that it uses OpenGL 2.1  

***

[more help and instructions](web_Help_Res/content_help.md)




________



 



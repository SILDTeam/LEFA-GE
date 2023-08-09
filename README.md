brazil format - DD.MM.YY  
code Version ``01.08.23``  

##  <img src="web_Help_Res/LEFA_LOGO.png" width="40" height="40" />  LITHE ENGINE FOR ALL  

<img src="web_Help_Res/Troll Face.ico" width="35" height="35" />yes, it's another render being developed in this world, and to make matters worse being created with limitations.

the project is being done in another way  ...  

this code is just the beginning/studies/research of what this could be in the future  
the code is totally poorly optimized
## what you need, to build.
the code is being written in | C 90 and C++ 98  
  
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
you need to place the files from the more_Files/windows directory  inside the Open Watcom installation location  
the default location is ``C:\WATCOM``  
    
</details>

### Install Watcom and Configure Project to linux info.
</div>
  <details>
   <summary> FOR LINUX  </summary>  
    
### step 1
you need to extract open-watcom-c-linux-1.9 file  
and put his files in a directory called WATCOM  
then you will move this directory to  

`` /usr/bin ``  
  
getting like this ` /usr/bin/WATCOM `   

### step 2  

you need a script and define Watcom Files path to linux put the code in `.bashrc `   
and now put the entire code below inside the .bashrc file, open the .bashrc and at the end of it put the following code.

```sh
# Linux 32-bit shell script:
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

NOTE ! libX11.a is not working in Open Watcom 1.9 , we need Compile libX11.a with Open Watcom .

</details>

________



 



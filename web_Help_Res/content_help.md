
### Systems

windows 
Linux 
BSD

***

#### build more help 

***

## Watcom compiler installation
</div>
  <details>
   <summary> FOR WINDOWS </summary>  
    


### Fixe watcom OpenGL Syntax Error! 
put OpenGl Modified / Fixed Files Incluse in [more_Files/Windows](../more_files/windows)  

  replace default WATCOM files  
you need to place the files from the ```more_Files/windows``` directory  inside the Open Watcom installation location  
the default location is ``C:\WATCOM``  
    
</details>


</div>
  <details>
   <summary> FOR LINUX  </summary>  
    
### Install Watcom and Configure Project for linux.

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

***

## build with Watcom

 <img src="../web_Help_Res/Watcom_mini.png" width="35" height="35" /> Open Watcom 1.9  
#### Open Watcom Downloads  

- [<img src="../web_Help_Res/windows_icon_aero.png" width="25" height="25" /> open-watcom-c-win32-1.9.exe](http://openwatcom.org/ftp/install/open-watcom-c-win32-1.9.exe)   

    
- <img src="../web_Help_Res/icons8-linux-96.png" width="25" height="25" />  [open-watcom-c-linux-1.9](http://openwatcom.org/ftp/install/open-watcom-c-linux-1.9)

***

### build  with other compilers.

GNU_GCC


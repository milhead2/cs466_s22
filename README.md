WSU CS 466 README
=================
Is intended to help setup the build environment for class so that we all do start from the same environment.

I locate all my development projects in a directory ```~/src``` Doing so allows me a consistant location scheme on any computer.  In linux the tilde character indicates your home directory.

It's not necessary that you use ```src``` as your parent directory but pick a directory that you treat as src of your own and install our class repo and development tools for class below it.  
If you experiance issues in lab it will help me isolate where the issue lies.  It 'should' also make all my ```make``` and ```cmake``` files work straight off without modification.

You will need git installed and possibly other applications as well (git, cmake, ) use ```sudo apt install``` for missing packages

 - The pico directory that I create below is a peer to the class CS466_S22 directory that you can install with the following commands
	- ```cd ~/src``` (or your replacement for src)
	- ```git clone git@github.com:milhead2/cs466_s22.git```
	
This file is the README.md from the class repo.

Build Environment Installation Steps
------------------------------------

 - Download SDK, examples and ARM compiler
	- ```cd ~/src``` (or your replacement for src)
	- ```mkdir pico```
	- ```cd pico```
	- ```git clone git@github.com:raspberrypi/pico-examples.git```
	- ```git clone git@github.com:raspberrypi/pico-sdk.git```
	- ```export PICO_SDK_PATH=~/src/pico/pico-sdk```  Also add this export to your .bashrc file, (I just append them at the bottom if the file)
		- ```echo "export PICO_SDK_PATH=~/src/pico/pico-sdk" >> ~/.bashrc```  Be very sure you append with ```>>`` or you can overwrite your bashrc file.
	- ```cd ~/src```
 - Build the SDK and examples dir.  This may require additional software installs...  The compiler install is below.
    - ```cd ../pico-examples```
	- ```git submodule update --init```  
	- ```cmake .```
	- ```make```
    - ```cd ../pico-sdk```
	- ```git submodule update --init```  
	- ```cmake .```
	- ```make```
	export PICO_SDK_PATH=~/src/pico/pico-sdk
	
 - If you do not have the ARM GCC compiler installed you can get it from here..
	- ```cd ~/src```
	- ```mkdir bin```
	- ```cd bin```
	- ```wget https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.10/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2```
	- ```bzip2 -d gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2```
	- ```tar xvf gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar```
	- Make sure that ths binary directory of this compuler is in your path
	- ```export PATH=$PATH:~/src/pico/bin/gcc-arm-none-eabi-10.3-2021.10/bin```  Also add this export to your .bashrc file, (I just append them at the bottom if the file)
		- ```echo "export PATH=$PATH:~/src/pico/bin/gcc-arm-none-eabi-10.3-2021.10/bin" >> ~/.bashrc```  Be very sure you append with ```>>`` or you can overwrite your bashrc file.
	- ```cd ..```
	- Verify that you can see the installed compiler in your path
	- ``` arm-none-eabi-gcc --version```
	- Should produce the output...
		```
		arm-none-eabi-gcc (GNU Arm Embedded Toolchain 10.3-2021.10) 10.3.1 20210824 (release)
		Copyright (C) 2020 Free Software Foundation, Inc.
		This is free software; see the source for copying conditions.  There is NO
		warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
		```


Build Provided Lab One Code
---------------------------

- We will using cmake to generate a Makefile 

	- You should have you CS466_S22 repo in a peer directory to the pico tools.  For me that is ```~/src/cs466_s22``` and the pico tools in ```~/src/pico```
	- Create a build directory and make it your current dir
		- ```cd ~/src/cs466_s22/lab1```
		- ```mkdir build```
		- ```cd build```
	- Call ```cmake``` to generate a makefile
		- ```cmake ..```
	- Then use ```make``` to build the SDK and the lab1 code
		- ```make```
	- If the make is successful, the file ```lab1.uf2``` will be created in the build directory.  To execute that file reboot the pico into 
	drive-loader-mode by booting with the button pressed and copy the ```lab1.uf2``` to the faux drive that the pico creates.
		- ```cp lab1.uf2 /media/miller/RPI-RP2```
		


	
		
		
		
		
	18274  cd pico/
18276  cd pico-examples/
18286  cd ..
18291  git clone git@github.com:raspberrypi/pico-sdk.git
$ cd blink
$ cp blink.uf2 /media/miller/RPI-RP2


wget https://github.com/FreeRTOS/FreeRTOS-LTS/releases/download/202012.03-LTS/FreeRTOSv202012.03-LTS.zip


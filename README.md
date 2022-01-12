WSU CS 466 README
=================
Is intended to help setup the build environment for class so that we all do start from the same environment.

I locate all my development projects in a directory ```~/src``` Doing so allows me a consistant location scheme on any computer.  In linux the tilde character indicates your home directory.

It's not necessary that you use ```src``` as your parent directory but pick a directory that you treat as src of your own and install our class repo and development tools for class below it.  
If you experiance issues in lab it will help me isolate where the issue lies.  It 'should' also make all my ```make``` and ```cmake``` files work straight off without modification.

You will need git installed and possibly other applications as well (git, cmake, ) use ```sudo apt install``` for missing packages

 - Download SDK, examples and ARM compiler
	- ```cd ~/src``` (or your replacement for src)
	- ```mkdir pico```
	- ```cd pico```
	- ```git clone git@github.com:raspberrypi/pico-examples.git```
	- ```git clone git@github.com:raspberrypi/pico-sdk.git```
	- ```export PICO_SDK_PATH=~/src/pico/pico-sdk```  Also add this export to your .bashrc file, (I just put them onthe bottom)
		- ```echo "export PICO_SDK_PATH=~/src/pico/pico-sdk" >> ~/.bashrd```  Be very sure you append with ```>>`` or you can overwrite your bashrc file.
	- ```cd ~/src```
	- ```git submodule update --init```  
    - ```cd ../pico-examples```
	- ```cmake .```
	- ```make```
	
 - If you do not have the ARM GCC compiler installed you can get it from here..
	- ```cd ~/src```
	- ```mkdir bin```
	- ```cd bin```
	- ```wget https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.10/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2```
	- ```bzip2 -d gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2```
	- ```tar xvf gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar```
	- ```cd ..```
		
		
		
		
	18274  cd pico/
18276  cd pico-examples/
18286  cd ..
18291  git clone git@github.com:raspberrypi/pico-sdk.git
$ cd blink
$ cp blink.uf2 /media/miller/RPI-RP2


wget https://github.com/FreeRTOS/FreeRTOS-LTS/releases/download/202012.03-LTS/FreeRTOSv202012.03-LTS.zip


# Basic Platformer

For this project I wanted to learn C++ and use the SDL2 library to create a basic action platformer game.

## Motivation

This project was inspired 

## Getting Started

### Preprequisites

- [C++](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download)
- [SDL2 Library](https://www.libsdl.org/download-2.0.php)

#### Installing prerequisites on Windows
1. Follow tutorial to install on [windows](https://www.matsson.com/prog/sdl2-mingw-w64-tutorial.php)

#### Installing prerequisites on Ubuntu/Debian
1. First check if C/C++ compiler is installed by opening up the terminal and enter the command

		g++ --version

2. If you see a g++ version then you can skip the following steps. Otherwise, continue following the steps below in your terminal

3. Update and upgrade the repositories

		sudo apt update && sudo apt upgrade

4. Install g++

		sudo apt install g++

5. Check g++ version

		g++ --version

### Installing
1. You can either download the zip file and upzip it or clone th repository

		git clone https://github.com/TvDragon/basic_platformer_cpp.git
	
## Usage

1. Once you have installed the prerequisites and unzipped the file or cloned the repository move into the folder

2. If you use Ubuntu/Debian then you can run the command below which will compile the files using a Makefile

		make play

3. If you use Windows then you must open manually copy the command below and paste that into command prompt or a terminal

		g++ main.cpp entity.cpp draw_objects.cpp check_collision.cpp object_detection.cpp render_window.cpp -std=c++14 -m64 -g -I include -I C:/SDL2-w64/include -L C:/SDL2-w64/lib -lmingw32 -lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf play

4. Run the game by entering the command below

		./play
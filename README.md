# Basic Platformer
## Motivation

This is a basic platformer game that I made during the holidays in my second year of uni as I wanted to teach myself how to write in C++ and use the SDL2 library. You play as a hero who must fight his way through the level slashing down enemies and crates along with collecting keys to open chests and collect coins.

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

2. If you use Ubuntu/Debian then you can run the command below which will compile the files using a Makefile then you can run the game

		make play
		./play

3. If you use Windows then you need to open the play folder and double click on play.exe to play the game

## Playing the game

- Jump - spacebar
- Move Left - left arrow key
- Move Right - right arrow key
- Attack One - z
- Attack Two - x
- Attack Three - c

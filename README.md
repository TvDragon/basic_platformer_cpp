# Basic Platformer
## Motivation

This is a basic platformer game that I made during the holidays in my second year of uni as I wanted to teach myself how to write in C++ and use the SDL2 library. You play as a hero who must fight his way through the level slashing down enemies and crates along with collecting keys to open chests and collect coins.

## Getting Started

### Optional Dependency Installs

Note: You do not have to install the necessary libraries to play as they are already included in the downloads. You can move down to the usage section to start playing the game. However if the game doesn't work then you may have to follow the install guide below.

- [C++](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download)
- [SDL2 Library](https://www.libsdl.org/download-2.0.php)

#### Installing on Ubuntu/Debian
1. First check if C/C++ compiler is installed by opening up the terminal and enter the command

		g++ --version

2. If you see a g++ version then you can skip the following steps. Otherwise, continue following the steps below in your terminal

3. Update and upgrade the repositories

		sudo apt update && sudo apt upgrade

4. Install g++

		sudo apt install g++

5. Check g++ version

		g++ --version

6. Install the SDL2 Library by entering the command below in your terminal

		sudo apt install build-essential libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev

Note: The package manager you use will be different depending on which linux system you use. You can find your package manager by searching it on the internet if you don't know then install the libraries.

## Installing the game
If you want to install the source code or appimage for Linux you can download it at [Linux Build](https://github.com/TvDragon/basic_platformer_cpp/releases/tag/Linux)

## Usage

1. Once you have installed and unzipped the file or cloned the repository move into the folder

2. If you use Ubuntu/Debian move into folder you unzipped then you can run the command in your terminal in the directory that you downloaded the game to and start playing the game

		sh play.sh

3. If you prefer using an app image then run the command below in your terminal in the directory that you downloaded the game and start playing the game by double clicking on it

		chmod a+x Basic_Platformer-x86_64.AppImage

## Controls

- Jump - spacebar
- Move Left - left arrow key
- Move Right - right arrow key
- Attack One - z
- Attack Two - x
- Attack Three - c

## Video Gameplay

https://github.com/TvDragon/basic_platformer_cpp/assets/67213501/4c152e09-b596-4a1f-a075-1cdb27305563

CC=g++
CFLAGS=-std=c++14 -m64 -g -lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf
basic_platformer: src/*.cpp
	$(CC) $^ $(CFLAGS) -o $@

clean:
	rm basic_platformer

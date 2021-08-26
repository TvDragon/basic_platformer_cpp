CC=g++
CFLAGS=-std=c++14 -m64 -g -I include -I C:/SDL2-w64/include -L C:/SDL2-w64/lib -lmingw32 -lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf
play: src/*.cpp
	$(CC) $^ $(CFLAGS) -o $@

clean:
	rm play
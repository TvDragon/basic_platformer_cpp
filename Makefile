CC=g++
CFLAGS=-std=c++11 -mwindows -IC:/SDL2-w64/include -LC:/SDL2-w64/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf

play: src/*.cpp
	$(CC) $^ $(CFLAGS) -o $@

clean:
	rm play
SRCS = src/main.cpp

default:
	mkdir -p bin
	clang++ -std=c++17 -Iinclude -I/home/jc/Documents/GameDev/raylib/src/ $(SRCS) -L/home/jc/Documents/GameDev/raylib/src/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o bin/main

clean:
	rm -rf bin

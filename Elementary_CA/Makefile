SRCS = src/main.cpp

default:
	mkdir -p bin
	clang++ -std=c++17 -Iinclude -I/home/j_c/Work/Projects/cpp_projects/raylib/src/ $(SRCS) -L/home/j_c/Work/Projects/cpp_projects/raylib/src/ -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o bin/main

clean:
	rm -rf bin

SRCS = src/main.cpp

default:
	mkdir -p bin
	clang++ -std=c++17 -Iinclude -I./include $(SRCS) -L./lib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o bin/main

clean:
	rm -rf bin

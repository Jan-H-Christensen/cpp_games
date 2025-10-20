
# Alle Quelldateien hier auflisten
SRCS = src/main.cpp src/grid.cpp src/colors.cpp src/block.cpp src/blocks.cpp src/position.cpp

default:
	mkdir -p bin
	clang++ -std=c++17 -Iinclude -Isrc $(SRCS) -Llib -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o bin/main 

clean:
	rm -rf bin

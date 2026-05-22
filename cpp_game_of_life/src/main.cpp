// this is my try to recreate the game of life fram Conways

#include "raylib.h"
#include <mm_malloc.h>
#include <vector>

int main() {
  // window init
  const int screenWidth = 800;
  const int screenHight = 600;
  InitWindow(screenWidth, screenHight, "Game of life - Test");

  // board
  int rows = 30;
  int cols = 40;
  std::vector<std::vector<int>> grid(rows, std::vector<int>(cols, 0));

  SetTargetFPS(60);

  // Spielfeld zufällig füllen
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      // rand() % 2 liefert zufällig 0 oder 1
      grid[r][c] = rand() % 2;
    }
  }
  // game loop
  while (!WindowShouldClose()) {
    // Logic

    std::vector<std::vector<int>> nextGrid = grid;

    // drawing
    BeginDrawing();

    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        int posX = c * 20;
        int posY = r * 20;

        if (grid[r][c] == 1) {
          DrawRectangle(posX, posY, 20, 20, BLACK);
        } else {
          DrawRectangle(posX, posY, 20, 20, GRAY);
        }
      }
    }

    ClearBackground(RAYWHITE);
    DrawText("raylib and c++ works", 10, 10, 20, DARKGRAY);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}

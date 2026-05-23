// this is my try to recreate the game of life fram Conways

#include "raylib.h"
#include <mm_malloc.h>
#include <vector>

int main() {
  // window init
  const int screenWidth = 1600;
  const int screenHight = 1200;
  InitWindow(screenWidth, screenHight, "Game of life - Test");

  // board
  int rows = 300;
  int cols = 400;
  std::vector<std::vector<int>> grid(rows, std::vector<int>(cols, 0));

  double lastUpdateTime = 0.0;
  double updateInterval = 0.1;

  bool isPaused = false;

  SetTargetFPS(60);

  /* Spielfeld zufällig füllen
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      // rand() % 2 liefert zufällig 0 oder 1
      grid[r][c] = rand() % 2;
    }
  }
  */
  // game loop
  while (!WindowShouldClose()) {
    double currentTime = GetTime();

    if (IsKeyPressed(KEY_SPACE)) {
      isPaused = !isPaused;
    }

    // 2. Maus-Eingabe für das Zeichnen von Zellen
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) ||
        IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
      Vector2 mousePos = GetMousePosition();

      // Pixel-Koordinaten in Raster-Indizes umrechnen
      int c = mousePos.x / 20;
      int r = mousePos.y / 20;

      // Sicherheitscheck: Nur im Spielfeld reagieren, um Abstürze zu vermeiden
      if (r >= 0 && r < rows && c >= 0 && c < cols) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
          grid[r][c] = 1; // Linksklick: Zelle wird lebendig
        } else if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
          grid[r][c] = 0; // Rechtsklick: Zelle stirbt
        }
      }
    }

    if (currentTime - lastUpdateTime >= updateInterval && !isPaused) {
      // Logic
      // 1.0 A copy of the corrent state of the grid
      std::vector<std::vector<int>> nextGrid = grid;

      // 2.0 state check of every cell
      for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {

          int aliveNeighbors = 0;

          for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {

              if (i == 0 && j == 0) {
                continue;
              }

              // 2.5 Toroidale edge calculation (Pac-Man-Effect)
              int neighborRow = (r + i + rows) % rows;
              int neighborCol = (c + j + cols) % cols;

              // if neighbor is alive incr. counter
              if (grid[neighborRow][neighborCol] == 1) {
                aliveNeighbors++;
              }
            }
          }

          // 3. Conway Rule
          if (grid[r][c] == 1) {

            if (aliveNeighbors == 2 || aliveNeighbors == 3) {
              nextGrid[r][c] = 1;
            } else {
              nextGrid[r][c] = 0;
            }

          } else {

            if (aliveNeighbors == 3) {
              nextGrid[r][c] = 1;
            } else {
              nextGrid[r][c] = 0;
            }
          }
        }
      }

      // 4. update new state of the grid
      grid = nextGrid;
      lastUpdateTime = currentTime;
    }

    // drawing
    BeginDrawing();
    ClearBackground(RAYWHITE);

    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        int posX = c * 20;
        int posY = r * 20;

        if (grid[r][c] == 1) {
          DrawRectangle(posX, posY, 20, 20, BLACK);
        } else {
          DrawRectangleLines(posX, posY, 20, 20, GRAY);
        }
      }
    }

    // DrawText("raylib and c++ works", 10, 10, 20, DARKGRAY);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}

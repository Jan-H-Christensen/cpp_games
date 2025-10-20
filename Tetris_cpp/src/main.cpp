#include "blocks.cpp"
#include "grid.h"
#include "raylib.h"

int main() {
  // init app

  InitWindow(400, 800, "Tetris creazy");
  SetTargetFPS(60);

  Grid grid = Grid();
  grid.Print();

  IBlock block = IBlock();

  // run app

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(PURPLE);
    grid.Draw();
    block.Draw();
    EndDrawing();
  }

  // close app

  CloseWindow();

  return 0;
}

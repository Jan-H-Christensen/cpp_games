#include "game.h"
#include "raylib.h"

double lastUpdateTime = 0;

bool EventTriggered(double interval) {
  double currentTime = GetTime();
  if (currentTime - lastUpdateTime >= interval) {
    lastUpdateTime = currentTime;
    return true;
  }
  return false;
}

int main() {
  // init app

  InitWindow(450, 520, "Tetris creazy");
  SetTargetFPS(60);

  Font font =
      LoadFontEx("fonts/Bitcount_Grid_Single/"
                 "BitcountGridSingle-VariableFont_CRSV,ELSH,ELXP,slnt,wght.ttf",
                 64, 0, 0);
  Game game = Game();

  // run app

  while (!WindowShouldClose()) {

    game.HandleInput();

    if (EventTriggered(0.2)) {
      game.MoveBlockDown();
    }

    BeginDrawing();
    ClearBackground(PURPLE);
    DrawTextEx(font, "Score", {300, 15}, 38, 2, WHITE);
    game.Draw();
    EndDrawing();
  }

  // close app

  CloseWindow();

  return 0;
}

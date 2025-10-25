#include "game.h"
#include "raylib.h"
#include <cstdio>

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

  Font font = LoadFontEx(
      "fonts/BitcountGridSingle-VariableFont_CRSV,ELSH,ELXP,slnt,wght.ttf", 64,
      0, 0);
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
    DrawRectangleRounded({265, 55, 170, 60}, 0.3, 6, DARKPURPLE);

    char scoreText[10];
    sprintf(scoreText, "%d", game.score);
    Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

    DrawTextEx(font, scoreText, {300 + (170 - textSize.x) / 2, 70}, 38, 2,
               WHITE);
    DrawTextEx(font, "Next", {305, 165}, 38, 2, WHITE);
    DrawRectangleRounded({265, 205, 170, 170}, 0.3, 6, DARKPURPLE);
    game.Draw();
    if (game.gameOver) {
      DrawTextEx(font, "Game", {60, 200}, 72, 2, WHITE);
      DrawTextEx(font, "Over", {60, 260}, 72, 2, WHITE);
    }
    EndDrawing();
  }

  // close app

  CloseWindow();

  return 0;
}

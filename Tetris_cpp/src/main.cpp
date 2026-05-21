#include "game.h"
#include "raylib.h"
#include "ui_manager.h"
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
  InitWindow(450, 520, "Tetris creazy");
  SetTargetFPS(60);

  Font font = LoadFontEx(
      "fonts/BitcountGridSingle-VariableFont_CRSV,ELSH,ELXP,slnt,wght.ttf", 64,
      0, 0);

  GameScreen currentScreen = SCREEN_STARTMENU;
  GameArea currentArea = AREA_HUB;
  Game *game = new Game();

  while (!WindowShouldClose()) {

    Vector2 mousePos = GetMousePosition();
    bool mouseClicked = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

    // ----------------------------------------------------
    // 1. UPDATE & INPUT LOGIC
    // ----------------------------------------------------
    if (currentScreen == SCREEN_STARTMENU) {
      int btnWidth = 260;
      int btnHeight = 45;
      int btnX = 450 / 2 - btnWidth / 2;
      Rectangle rectLeaveGame = {(float)btnX, 340, (float)btnWidth,
                                 (float)btnHeight};

      if (CheckCollisionPointRec(mousePos, rectLeaveGame) && mouseClicked) {
        break;
      }
    } else if (currentScreen == SCREEN_MAINGAME) {

      // Smart Back Button Click Processing
      Rectangle rectTabBack = {340, 10, 100, 35};
      if (CheckCollisionPointRec(mousePos, rectTabBack) && mouseClicked) {
        if (currentArea == AREA_HUB) {
          currentScreen = SCREEN_STARTMENU;
          game->gameStarted = false;
        } else {
          currentArea = AREA_HUB;
          game->gameStarted = false;
        }
      }

      // Hub Selection State
      if (currentArea == AREA_HUB) {
        Rectangle rectGoToPlay = {95, 180, 260, 50};
        Rectangle rectGoToCraft = {95, 260, 260, 50};

        if (CheckCollisionPointRec(mousePos, rectGoToPlay) && mouseClicked) {
          currentArea = AREA_PLAY;
          game->gameStarted =
              true; // <--- FIXED: Unlocks the game.cpp input block!
        }
        if (CheckCollisionPointRec(mousePos, rectGoToCraft) && mouseClicked) {
          currentArea = AREA_CRAFTING;
        }
      }
      // Active Tetris Gameplay State
      else if (currentArea == AREA_PLAY) {
        if (game->gameOver) {
          // Custom Keyboard handling for Game Over state
          if (IsKeyPressed(KEY_R)) {
            delete game;
            game = new Game();
            game->gameStarted = true; // Stay in play mode
          }
          if (IsKeyPressed(KEY_M)) {
            delete game;
            game = new Game();
            currentArea = AREA_HUB; // Back to menu hub
          }
        } else {
          UpdateMusicStream(game->music);

          // FIXED: This will now process arrow keys perfectly!
          game->HandleInput();

          if (EventTriggered(0.2)) {
            game->MoveBlockDown();
          }
        }
      }
    }

    // ----------------------------------------------------
    // 2. DRAWING LOGIC
    // ----------------------------------------------------
    BeginDrawing();
    ClearBackground(PURPLE);

    if (currentScreen == SCREEN_STARTMENU) {
      DrawStartMenu(font, mousePos, mouseClicked, currentScreen, currentArea);

      int btnWidth = 260;
      int btnHeight = 45;
      int btnX = 450 / 2 - btnWidth / 2;
      DrawRectangleRounded(
          {(float)btnX, 340, (float)btnWidth, (float)btnHeight}, 0.3, 6,
          DARKPURPLE);
      DrawTextEx(font, "Leave Game", {(float)btnX + 55, 350}, 22, 2, WHITE);
    } else if (currentScreen == SCREEN_MAINGAME) {

      DrawRectangleRounded({340, 10, 100, 35}, 0.3, 6, RED);
      DrawTextEx(font, "Back", {370, 18}, 18, 2, WHITE);

      if (currentArea == AREA_HUB) {
        DrawMainHub(font, mousePos, mouseClicked, currentArea);
      } else if (currentArea == AREA_PLAY) {
        DrawTextEx(font, "Score", {300, 60}, 38, 2, WHITE);
        DrawRectangleRounded({265, 100, 170, 60}, 0.3, 6, DARKPURPLE);

        char scoreText[10];
        sprintf(scoreText, "%d", game->score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
        DrawTextEx(font, scoreText, {300 + (170 - textSize.x) / 2, 115}, 38, 2,
                   WHITE);

        DrawTextEx(font, "Next", {305, 210}, 38, 2, WHITE);
        DrawRectangleRounded({270, 250, 150, 150}, 0.3, 6, DARKPURPLE);

        game->Draw();

        if (game->gameOver) {
          DrawRectangle(0, 0, 450, 520, Fade(BLACK, 0.75f));
          DrawTextEx(font, "GAME OVER", {75, 160}, 52, 2, RED);
          DrawTextEx(font, "Press [R] to Try Again", {65, 260}, 22, 2, WHITE);
          DrawTextEx(font, "Press [M] for Main Hub", {65, 310}, 22, 2, WHITE);
        }
      } else if (currentArea == AREA_CRAFTING) {
        DrawCraftingScreen(font);
      }
    }

    EndDrawing();
  }

  delete game;
  CloseWindow();
  return 0;
}

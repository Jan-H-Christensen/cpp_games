#include "ui_manager.h"

void DrawStartMenu(Font font, Vector2 mousePos, bool mouseClicked,
                   GameScreen &currentScreen, GameArea &currentArea) {
  DrawTextEx(font, "TETRIS", {80, 100}, 80, 2, WHITE);

  int btnWidth = 260;
  int btnHeight = 45;
  int btnX = 450 / 2 - btnWidth / 2;

  Rectangle rectCreateGame = {(float)btnX, 220, (float)btnWidth,
                              (float)btnHeight};
  Rectangle rectLoadGame = {(float)btnX, 280, (float)btnWidth,
                            (float)btnHeight};

  // Draw & Handle Create Game
  DrawRectangleRounded(rectCreateGame, 0.3, 6, DARKPURPLE);
  DrawTextEx(font, "Create New Game", {(float)btnX + 25, 230}, 22, 2, WHITE);
  if (CheckCollisionPointRec(mousePos, rectCreateGame) && mouseClicked) {
    currentScreen = SCREEN_MAINGAME;
    currentArea = AREA_HUB;
  }

  // Draw & Handle Load Game
  DrawRectangleRounded(rectLoadGame, 0.3, 6, DARKPURPLE);
  DrawTextEx(font, "Load Game", {(float)btnX + 60, 290}, 22, 2, WHITE);
  if (CheckCollisionPointRec(mousePos, rectLoadGame) && mouseClicked) {
    currentScreen = SCREEN_MAINGAME;
    currentArea = AREA_HUB;
  }
}

void DrawMainHub(Font font, Vector2 mousePos, bool mouseClicked,
                 GameArea &currentArea) {
  DrawTextEx(font, "MAIN HUB", {120, 100}, 36, 2, WHITE);

  Rectangle rectGoToPlay = {95, 180, 260, 50};
  Rectangle rectGoToCraft = {95, 260, 260, 50};

  DrawRectangleRounded(rectGoToPlay, 0.3, 6, DARKPURPLE);
  DrawTextEx(font, "Play Tetris", {150, 192}, 24, 2, WHITE);
  if (CheckCollisionPointRec(mousePos, rectGoToPlay) && mouseClicked) {
    currentArea = AREA_PLAY;
  }

  DrawRectangleRounded(rectGoToCraft, 0.3, 6, DARKPURPLE);
  DrawTextEx(font, "Crafting Room", {135, 272}, 24, 2, WHITE);
  if (CheckCollisionPointRec(mousePos, rectGoToCraft) && mouseClicked) {
    currentArea = AREA_CRAFTING;
  }
}

void DrawCraftingScreen(Font font) {
  DrawRectangleRounded({20, 80, 410, 420}, 0.1f, 6, DARKPURPLE);
  DrawTextEx(font, "CRAFTING INVENTORY", {60, 120}, 26, 2, WHITE);
  // Future crafting slots logic go directly here!
}

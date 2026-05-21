#pragma once
#include "game.h"
#include "raylib.h"

// We pass enums by reference if we want the UI files to change them
typedef enum { SCREEN_STARTMENU, SCREEN_MAINGAME } GameScreen;
typedef enum { AREA_HUB, AREA_PLAY, AREA_CRAFTING } GameArea;

// Declarations of our drawing layouts
void DrawStartMenu(Font font, Vector2 mousePos, bool mouseClicked,
                   GameScreen &currentScreen, GameArea &currentArea);
void DrawMainHub(Font font, Vector2 mousePos, bool mouseClicked,
                 GameArea &currentArea);
void DrawCraftingScreen(Font font);

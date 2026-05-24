#include "raylib.h"

int main() {
  // Fenster initialisieren
  const int screenWidth = 800;
  const int screenHeight = 600;
  InitWindow(screenWidth, screenHeight, "Game of Life - Test");

  SetTargetFPS(60);

  // Hauptschleife
  while (!WindowShouldClose()) {
    // Logik
    
    // Zeichnen
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("raylib und C++ laufen!", 10, 10, 20, DARKGRAY);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}

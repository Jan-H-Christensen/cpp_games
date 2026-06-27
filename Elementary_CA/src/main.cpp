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
    for (int i = 0; i < screenWidth / 5; i++) {
      for (int j = 0; j < screenHeight / 5; j++) {
        DrawRectangleLines(i * 5, j * 5, 5, 5, BLUE);
      }
    }
    EndDrawing();
  }

  CloseWindow();
  return 0;
}

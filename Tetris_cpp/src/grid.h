#pragma once
#include "raylib.h"
#include <vector>

class Grid {
public:
  Grid();
  void Initialize();
  void Print();
  void Draw();
  int grid[40][20];

private:
  int numRow;
  int numCol;
  int cellSize;
  std::vector<Color> colors;
};

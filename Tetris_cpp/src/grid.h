#pragma once
#include "raylib.h"
#include <vector>

class Grid {
public:
  Grid();
  void Initialize();
  void Print();
  void Draw();
  bool isCellOutside(int row, int column);
  bool isCellEmpty(int row, int column);
  int ClearFullRows();
  int grid[30][20];

private:
  bool isRowFull(int row);
  void ClearRow(int row);
  void MoveRowDown(int row, int numRows);
  int numRow;
  int numCol;
  int cellSize;
  std::vector<Color> colors;
};

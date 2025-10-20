#include "grid.h"
#include "colors.h"
#include "raylib.h"
#include <iostream>

Grid::Grid() {
  numRow = 40;
  numCol = 20;
  cellSize = 20;
  Initialize();
  colors = GetCellColors();
}

void Grid::Initialize() {
  for (int row = 0; row < numRow; row++) {
    for (int column = 0; column < numCol; column++) {
      grid[row][column] = 0;
    }
  }
}

void Grid::Print() {
  for (int row = 0; row < numRow; row++) {
    for (int column = 0; column < numCol; column++) {
      std::cout << grid[row][column] << " ";
    }
    std::cout << std::endl;
  }
}

void Grid::Draw() {
  for (int row = 0; row < numRow; row++) {
    for (int column = 0; column < numCol; column++) {
      int cellValue = grid[row][column];
      DrawRectangle(column * cellSize + 1, row * cellSize + 1, cellSize - 1,
                    cellSize - 1, colors[cellValue]);
    }
  }
}

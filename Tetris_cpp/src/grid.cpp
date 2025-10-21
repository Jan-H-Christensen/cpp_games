#include "grid.h"
#include "colors.h"
#include "raylib.h"
#include <cstdlib>
#include <iostream>

Grid::Grid() {
  numRow = 30;
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

bool Grid::isCellOutside(int row, int column) {
  if (row >= 0 && row <= numRow - 1 && column >= 0 && column <= numCol - 1) {
    return false;
  }
  return true;
}

bool Grid::isCellEmpty(int row, int column) {
  if (grid[row][column] == 0) {
    return true;
  }
  return false;
}

int Grid::ClearFullRows() {
  int completed = 0;
  for (int row = numRow - 1; row >= 0; row--) {
    if (isRowFull(row)) {
      ClearRow(row);
      completed++;
    } else if (completed > 0) {
      MoveRowDown(row, completed);
    }
  }
  return completed;
}

bool Grid::isRowFull(int row) {
  for (int column = 0; column < numCol; column++) {
    if (grid[row][column] == 0) {
      return false;
    }
  }
  return true;
}

void Grid::ClearRow(int row) {
  for (int column = 0; column < numCol; column++) {
    grid[row][column] = 0;
  }
}

void Grid::MoveRowDown(int row, int numRows) {
  for (int column = 0; column < numCol; column++) {
    grid[row + numRows][column] = grid[row][column];
    grid[row][column] = 0;
  }
}

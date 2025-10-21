#pragma once

#include "colors.h"
#include "position.h"
#include <map>
#include <vector>

class Block {
public:
  Block();
  void Draw();
  void Move(int rows, int columns);
  void Rotate();
  void UndoRotate();
  std::vector<Position> GetCellPosition();
  int id;
  std::map<int, std::vector<Position>> cells;

private:
  int cellSize;
  int rotationState;
  std::vector<Color> colors;
  int rowOffset;
  int columOffset;
};

#include "block.h"
#include "position.h"
#include <vector>

Block::Block() {
  cellSize = 20;
  rotationState = 0;
  colors = GetCellColors();
  rowOffset = 0;
  columOffset = 0;
}

void Block::Draw() {
  std::vector<Position> tiles = GetCellPosition();
  for (Position item : tiles) {
    DrawRectangle(item.column * cellSize + 1, item.row * cellSize + 1,
                  cellSize - 1, cellSize - 1, colors[id]);
  }
}

void Block::Move(int rows, int columns) {
  rowOffset += rows;
  columOffset += columns;
}

std::vector<Position> Block::GetCellPosition() {
  std::vector<Position> tiles = cells[rotationState];
  std::vector<Position> movedTiles;

  for (Position item : tiles) {
    Position newPos = Position(item.row + rowOffset, item.column + columOffset);
    movedTiles.push_back(newPos);
  }
  return movedTiles;
}

void Block::Rotate() {
  rotationState++;
  if (rotationState == cells.size()) {
    rotationState = 0;
  }
}

void Block::UndoRotate() {
  rotationState--;
  if (rotationState == -1) {
    rotationState = cells.size() - 1;
  }
}

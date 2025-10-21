#pragma once
#include "block.h"
#include "grid.h"
#include <blocks.cpp>
#include <vector>

class Game {
public:
  Game();
  Grid grid;
  bool gameOver;
  Block GetRandomBlock();
  std::vector<Block> GetAllBlocks();
  void Draw();
  void HandleInput();
  void MoveBlockLeft();
  void MoveBlockRight();
  void MoveBlockDown();

private:
  double softDropLastUpdateTime;
  bool isBlockOutside();
  void RotateBlock();
  void LockBlock();
  bool BlockFits();
  std::vector<Block> blocks;
  Block currentBlock;
  Block nextBlock;
  void Reset();
};

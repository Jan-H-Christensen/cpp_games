#pragma once
#include "block.h"
#include "grid.h"
#include "raylib.h"
#include <blocks.cpp>
#include <vector>

class Game {
public:
  Game();
  ~Game();
  void Draw();
  void HandleInput();
  void MoveBlockDown();
  bool gameOver;
  int score;
  Music music;

private:
  double softDropLastUpdateTime;
  bool isBlockOutside();
  bool BlockFits();
  Grid grid;
  Block currentBlock;
  Block nextBlock;
  Block GetRandomBlock();
  std::vector<Block> GetAllBlocks();
  std::vector<Block> blocks;
  void RotateBlock();
  void LockBlock();
  void Reset();
  void UpdateScore(int linesCleared, int movedDownPoints);
  void MoveBlockLeft();
  void MoveBlockRight();
  Sound rotateSound;
  Sound claerSound;
};

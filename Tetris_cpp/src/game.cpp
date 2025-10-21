#include "game.h"
#include "block.h"
#include "grid.h"
#include "position.h"
#include "raylib.h"
#include <codecvt>
#include <cstdlib>
#include <vector>

Game::Game() {
  grid = Grid();
  blocks = GetAllBlocks();
  currentBlock = GetRandomBlock();
  nextBlock = GetRandomBlock();
  gameOver = false;
  softDropLastUpdateTime = 0;
}
Block Game::GetRandomBlock() {
  if (blocks.empty()) {
    blocks = GetAllBlocks();
  }

  int randIndex = rand() % blocks.size();
  Block block = blocks[randIndex];

  blocks.erase(blocks.begin() + randIndex);
  return block;
}

std::vector<Block> Game::GetAllBlocks() {
  return {IBlock(), JBlock(), LBlock(), SBlock(), ZBlock(), OBlock(), TBlock()};
}

void Game::Draw() {
  grid.Draw();
  currentBlock.Draw();
}

void Game::HandleInput() {
  int keyPressed = GetKeyPressed();
  if (gameOver && keyPressed != 0) {
    gameOver = false;
    Reset();
  }

  if (IsKeyDown(KEY_DOWN)) {
    double currentTime = GetTime();
    if (currentTime - softDropLastUpdateTime >= 0.1) {
      MoveBlockDown();
      softDropLastUpdateTime = currentTime;
    }
  }

  if (IsKeyDown(KEY_LEFT)) {
    double currentTime = GetTime();
    if (currentTime - softDropLastUpdateTime >= 0.1) {
      MoveBlockLeft();
      softDropLastUpdateTime = currentTime;
    }
  }

  if (IsKeyDown(KEY_RIGHT)) {
    double currentTime = GetTime();
    if (currentTime - softDropLastUpdateTime >= 0.1) {
      MoveBlockRight();
      softDropLastUpdateTime = currentTime;
    }
  }

  if (IsKeyDown(KEY_UP)) {
    double currentTime = GetTime();
    if (currentTime - softDropLastUpdateTime >= 0.1) {
      RotateBlock();
      softDropLastUpdateTime = currentTime;
    }
  }
}

void Game::MoveBlockLeft() {
  if (!gameOver) {
    currentBlock.Move(0, -1);
    if (isBlockOutside() || BlockFits() == false) {
      currentBlock.Move(0, 1);
    }
  }
}

void Game::MoveBlockRight() {
  if (!gameOver) {
    currentBlock.Move(0, 1);
    if (isBlockOutside() || BlockFits() == false) {
      currentBlock.Move(0, -1);
    }
  }
}

void Game::MoveBlockDown() {
  if (!gameOver) {
    currentBlock.Move(1, 0);
    if (isBlockOutside() || BlockFits() == false) {
      currentBlock.Move(-1, 0);
      LockBlock();
    }
  }
}

bool Game::isBlockOutside() {
  std::vector<Position> tiles = currentBlock.GetCellPosition();

  for (Position item : tiles) {
    if (grid.isCellOutside(item.row, item.column)) {
      return true;
    }
  }
  return false;
}

void Game::RotateBlock() {
  currentBlock.Rotate();
  if (isBlockOutside()) {
    currentBlock.UndoRotate();
  }
}

void Game::LockBlock() {
  std::vector<Position> tiles = currentBlock.GetCellPosition();
  for (Position item : tiles) {
    grid.grid[item.row][item.column] = currentBlock.id;
  }
  currentBlock = nextBlock;
  if (BlockFits() == false) {
    gameOver = true;
  }
  nextBlock = GetRandomBlock();
  grid.ClearFullRows();
}

bool Game::BlockFits() {
  std::vector<Position> tiles = currentBlock.GetCellPosition();
  for (Position item : tiles) {
    if (grid.isCellEmpty(item.row, item.column) == false) {
      return false;
    }
  }
  return true;
}

void Game::Reset() {
  grid.Initialize();
  blocks = GetAllBlocks();
  currentBlock = GetRandomBlock();
  nextBlock = GetRandomBlock();
}

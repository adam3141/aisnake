#pragma once

#include "aisnake.h"

#include <vector>
#include <span>

namespace aisnake
{
/* Our snake is headless */
class Board;
class Snake {
public:
  explicit Snake(Board* board, int max_segments);
  void step(const Direction& dir);
  std::span<const int> viewSegments() const;

  private:
  Direction _direction;
  std::vector<Direction> _segments;
  
  // Non-owning pointer to the game board
  Board* _board;
  
};
  
} // namespace aisnake

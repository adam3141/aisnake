#pragma once

#include "aisnake.h"

#include <memory>
#include <vector>

namespace aisnake {
enum class CellType {
  Empty,
  Wall,
  Snake,
  Food
};

class Snake;
class Board {
public:
  static std::unique_ptr<Board> createBoard(const Size &board_size);

private:
  Board(const Size &board_size, const Location &head_location);

  Size _board_size;
  Location _head_location;
  bool _pow2_width;

  std::vector<CellType> _cells;
  std::unique_ptr<Snake> _snake;
};
} // namespace aisnake

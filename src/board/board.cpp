#include "board.h"

#include <chrono>
#include <random>

namespace aisnake {
Board::Board(const Size &board_size, const Location &head_location)
    : _board_size(board_size)
    , _head_location(head_location)
    , _pow2_width(board_size.width)
    , _cells(board_size.width * board_size.height, CellType::Empty) {}

std::unique_ptr<Board> Board::createBoard(const Size &board_size) {
  // The board size will need to be at least 10x10. If not, we can return a nullptr.
  if (board_size.width < 10 || board_size.height < 10) {
    return nullptr;
  }

  // Choose a random starting location for the snake
  std::mt19937 rng(std::chrono::high_resolution_clock().now().time_since_epoch().count());

  // Note: The uniform distribution is from the closed interval [a,b].
  std::uniform_int_distribution<int> height_dist(1, board_size.height - 2);
  std::uniform_int_distribution<int> width_dist(1, board_size.width - 2);
  Location head_location{width_dist(rng), height_dist(rng)};

  auto board = std::make_unique<Board>(board_size, head_location);

  /* Adding the walls to the game board
   *
   * It is done by adding the north and south walls first
   * Last is adding the west wand east walls
   *
   * This example board size is (10x5)
   *
   *  (0,0) +--------+ (9,0)
   *        |        |
   *        |        |
   *        |        |
   *  (0,4) +--------+ (9,4)
   */
  const int south_wall_start = board_size.width * (board_size.height - 1);
  // Place north and south wall
  for (int i = 0; i < board_size.width; i++) {
    board->_cells[i] = CellType::Wall;
    board->_cells[south_wall_start + i] = CellType::Wall;
  }
  // Place west and east wall
  for (int i = board_size.width; i < south_wall_start; i += board_size.width) {
    board->_cells[i] = CellType::Wall;
    board->_cells[i + board_size.width - 1] = CellType::Wall;
  }
  return std::move(board);
}


} // namespace aisnake
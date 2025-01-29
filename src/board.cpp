#include "board.h"

#include <bitset>
#include <chrono>
#include <random>

namespace {
constexpr bool testBit(int value, int bit) { return (value & (1 << bit)) != 0; }
} // namespace

namespace aisnake {
Board::Board(Size board_size)
    : _board_size{board_size},
      _game_board{board_size.width * board_size.height, BoardSymbols::Empty} {}

Board::~Board() {}

void Board::createBoard() {}

/*** Private Functions ***/
void Board::setStartLocation(Location &location, Direction &direction) {
  // Generate a randomized location. Checks that it doesn't start on a wall or a
  // void
  auto seed =
      std::chrono::high_resolution_clock::now().time_since_epoch().count();
  std::mt19937 rng(seed);

  const int num_directions = 4;

  std::uniform_int_distribution<int> generator_x(0, _board_size.width - 1);
  std::uniform_int_distribution<int> generator_y(0, _board_size.height - 1);
  std::uniform_int_distribution<int> generator_dir(0, num_directions - 1);

  bool location_valid{false};
  bool direction_valid{false};

  Location start_location{};
  Direction start_dir{};

  /*
   * Get a randomised value for the location and direction and check them
   * against where they're located on the game board.
   *
   * Because the location and direction are initially invalid, they will get a
   * value.
   */
  while (!location_valid || !direction_valid) {
    // Only update if invalid
    if (!location_valid) {
      start_location.x = generator_x(rng);
      start_location.y = generator_y(rng);
    }
    if (!direction_valid) {
      start_dir = toDirection(generator_dir(rng));
    }
  }
  // Check their validity
  location_valid = getBoardSymbol(start_location) == BoardSymbols::Empty;
}

BoardSymbols Board::getBoardSymbol(const Location &location) const {
  // Get offset into the board array and return the symbol located there.
  // Note: We don't do any checking here and assume that the location passed in
  // is within the bounds of the game board.
  int offset = location.x + location.y * _board_size.width;
  return _game_board[offset];
}

} // namespace aisnake
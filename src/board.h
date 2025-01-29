#pragma once

#include "board_symbols.h"
#include "snake_types.h"

#include <vector>

namespace aisnake {

/**
 * @brief Snake Game Board
 *
 * This object represents a game board that is capable of running the snake
 * game.
 *
 */
class Board {
public:
  /**
   * @brief Initialize the game board with a user defined size
   *
   * @param size_x The size of the board in the X direction
   * @param size_y The size of the board in the Y direction
   */
  Board(Size board_size);
  ~Board();

  /**
   * @brief Create a new empty gameboard
   *
   * This function overload initializes the game board with walls on the edges
   * of the game board.
   *
   * The snake also starts off with no body, that is, just a head and tail. The
   * location and direction of the snake is random however if the snake's
   * location starts too close to a wall, the direction is changed such that it
   * will not run into the wall within 5 moves.
   */
  void createBoard();

private:
  /**
   * @brief Set the snake start location and direction
   *
   * Determines a random start location and direction for the snake
   *
   * It will ensure that the snake cannot crash into a wall within 5 moves
   */
  void setStartLocation(Location &location, Direction &direction);

  BoardSymbols getBoardSymbol(const Location &location) const;

  Size _board_size;
  std::vector<BoardSymbols> _game_board;
};
} // namespace aisnake
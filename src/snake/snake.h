#pragma once

#include "aisnake.h"

#include <span>
#include <vector>

namespace aisnake {
/* Our snake is headless */
class Board;
class Snake {
public:
  static constexpr int MAX_SEGMENTS = 11;
  explicit Snake(int max_segments);
  ~Snake()=default;

  /**
   * @brief Move the snake in the current direction
   * @return The snakes body segments after the step
   */
  std::span<const Direction> step();

  /**
   * @brief Grow the snake
   *
   * The snake will grow from the head and will be evident after the next step
   * @return The snakes body segments after growing
   */
  std::span<const Direction> grow();

  void move(Direction direction);

  void printSnake();

private:
  //! The snake head and body.
  std::vector<Direction> _body;
};

} // namespace aisnake

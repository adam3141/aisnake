#include "snake.h"
#include "utils.h"
#include <iostream>
#include <stdexcept>

namespace aisnake {
Snake::Snake(int max_segments)
    : _body() {
  // Some validation is required
  if (max_segments > MAX_SEGMENTS) {
    throw std::invalid_argument("The minimum number of snake segments is 11");
  }

  // The first
  _body.push_back(Direction::North);
  _body.push_back(Direction::North);
  _body.push_back(Direction::North);
  _body.push_back(Direction::West);
  _body.push_back(Direction::West);
  _body.push_back(Direction::West);
  _body.push_back(Direction::West);

}

std::span<const Direction> Snake::step() {
  // From a digital electronics perspective, the snake is works like a shift register and we shift the directional
  // segments down it body. The segment connected to the snake's head will have the movement direction shifted into it.

  /* DEBUG */
  std::cout << "Before step: ";
  printSnake();
  std::cout << '\n';
  /* /DEBUG */

  for (int i = _body.size() - 1; i > 0;) {
    _body[i] = _body[--i];
  }

  /* DEBUG */
  std::cout << '\n';
  std::cout << "After step: ";
  printSnake();
  /* /DEBUG */

  return _body;
}

// std::span<const Direction> Snake::grow() {
//   if (_segments.size() != _segments.capacity()) {
//     // No more growing
//     _segments.push_back(_direction);
//   }
//   return _segments;
// }

void Snake::move(Direction direction) { _body[0] = direction; }

void Snake::printSnake() {
  for (const auto dir : _body) {
    std::cout << aisnake::toString(dir) << " ";
  }
  std::cout << '\n';
}
} // namespace aisnake

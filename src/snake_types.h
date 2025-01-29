#pragma once

#include <cstdint>

namespace aisnake {
struct Size {
  std::int32_t width;
  std::int32_t height;
};
struct Location {
  std::int32_t x;
  std::int32_t y;
};
enum Direction { North, East, South, West, Unkown };

// Overload for conversion of integer to Direction
Direction toDirection(int dir) {
  switch (dir) {
  case 0:
    return Direction::North;
  case 1:
    return Direction::East;
  case 2:
    return Direction::South;
  case 3:
    return Direction::West;
  default:
    return Direction::Unkown;
  }
}

} // namespace aisnake
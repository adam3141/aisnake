#include "utils.h"

#include <stdexcept>

namespace aisnake {

Direction oppositeDirection(const Direction &direction) {
  switch (direction) {
  case Direction::North:
    return Direction::South;
  case Direction::East:
    return Direction::West;
  case Direction::South:
    return Direction::North;
  case Direction::West:
    return Direction::East;
  default:
    throw std::invalid_argument("Direction not valid");
  };
}

} // namespace aisnake
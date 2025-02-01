#include "snake.h"

#include <iostream>
#include <memory>

using aisnake::Snake;
using aisnake::Direction;

int main() {
  auto snake = std::make_unique<aisnake::Snake>(11);

  snake->move(Direction::North);
  auto new_segments = snake->step();
 

  return 0;
}
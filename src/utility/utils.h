#pragma once

#include "snake_types.h"
#include <string>

namespace aisnake {
/**
 * @brief Direction opposite
 * 
 * Given a direction, this function returns its opposite
 * 
 * @param direction A Direction enumeration value
 * @return The opposite direction
 */
Direction oppositeDirection(const Direction& direction);

std::string toString(Direction direction);


}
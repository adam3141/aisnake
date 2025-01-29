#pragma once

#include <cstdint>

namespace aisnake {
enum class BoardSymbols : std::uint8_t {
  Empty,
  Wall,
  Head,
  Body,
  Tail,
  Food,
  Void
};
}
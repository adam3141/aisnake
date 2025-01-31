#pragma once

namespace aisnake {

//! Return true if x is a power of 2
constexpr bool isPow2(int x) { return x > 0 && (x & (x - 1)) == 0; }

} // namespace aisnake

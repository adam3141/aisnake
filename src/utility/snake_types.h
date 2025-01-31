#pragma once

namespace aisnake {
struct Size {
    int width;
    int height;
};
struct Location {
    int x;
    int y;
};
enum class Direction {
    North,
    East,
    South,
    West
};
}
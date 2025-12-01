#include <cmath>
#include <cstdio>
#include <iostream>
#include <sstream>

int main(int argc, char **argv) {
  int count = 0;
  int current = 50;

  std::string line;
  while (getline(std::cin, line)) {
    std::istringstream iss(line.c_str());
    int start = current;
    char rotation;
    int value;
    iss >> rotation >> value;

    // Calculate number of rotations
    count += std::floor(value / 100);
    value %= 100;

    current += rotation == 'L' ? -value : value;

    // Normalize position -1 < x < 100
    int padding = current < 0 ? 100 : current > 99 ? -100 : 0;
    current += padding;

    // Checks if the current position is 0 or if it crossed 0
    // check on start position is mandatory to avoid a false positive
    count += (current == 0) | (padding != 0 & start != 0);

    // printf("(%d%+d) -> %d: it: %d, pos: %d\n", start, value, current,
    //        iterations, rotates);
  }

  printf("Result: %d\n", count);
  return 0;
}

#include <cstdio>
#include <iostream>
#include <sstream>

int main(int argc, char **argv) {
  int count = 0;
  int position = 50;

  std::string line;
  while (getline(std::cin, line)) {
    std::istringstream iss(line.c_str());
    char rotation;
    int value;
    iss >> rotation >> value;

    value %= 100;
    position += rotation == 'L' ? -value : value;
    position += position < 0 ? 100 : position > 99 ? -100 : 0;
    count += position == 0;
  }

  printf("Result: %d\n", count);
  return 0;
}

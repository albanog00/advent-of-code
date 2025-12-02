#include <cstdio>
#include <iostream>

int main(int argc, char **argv) {
  int count = 0;
  int position = 50;
  int value;
  char rotation;

  while (std::cin >> rotation >> value) {
    value %= 100;
    position += rotation == 'L' ? -value : value;
    position = position < 0 ? 100 : position > 99 ? -100 : 0;
    count += position == 0;
  }

  printf("Result: %d\n", count);
  return 0;
}

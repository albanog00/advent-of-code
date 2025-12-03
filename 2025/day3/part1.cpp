#include <cstdint>
#include <cstdio>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  uint64_t count = 0;
  std::string line;

  while (std::cin >> line) {
    size_t size = line.size();
    char left = line[0];
    char right = line[1];

    for (size_t i = 1; i < size; ++i) {
      if (line[i] > left && i < size - 1) {
        left = line[i];
        right = line[i + 1];
      } else if (line[i] > right) {
        right = line[i];
      }
    }

    count += ((left - '0') * 10 + (right - '0'));
  }

  printf("Result: %zu\n", count);
  return 0;
}

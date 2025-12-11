#include <cassert>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <vector>

int main(int argc, char **argv) {
  uint64_t count = 0;
  std::vector<std::string> lines;
  std::string line;

  while (getline(std::cin, line)) {
    lines.push_back(line);
  }

  printf("Result: %zu\n", count);
  return 0;
}

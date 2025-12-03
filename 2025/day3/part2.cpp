#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  uint64_t count = 0;
  std::string line;

  while (std::cin >> line) {
    char jolt[12];
    size_t next = 0;

    for (size_t digit = 0; digit <= 11; ++digit) {
      size_t max = next;

      for (size_t i = max + 1; i < line.size() - (11 - digit); ++i) {
        if (line[i] > line[max]) {
          max = i;
        }
      }

      jolt[digit] = line[max];
      next = max + 1;
    }

    count += std::strtoull(jolt, nullptr, 10);
  }

  printf("Result: %zu\n", count);
  return 0;
}

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  uint64_t count = 0;
  std::string line;

  while (std::cin >> line) {
    size_t size = line.size();
    size_t sequence[12];

    size_t next = 0;
    for (size_t digit = 0; digit <= 11; ++digit) {
      sequence[digit] = next;

      for (size_t i = sequence[digit] + 1; i < size - (11 - digit); ++i) {
        if (line[i] > line[sequence[digit]]) {
          sequence[digit] = i;
        }
      }

      next = sequence[digit] + 1;
    }

    char jolt[12];
    for (size_t i = 0; i <= 11; ++i) {
      jolt[i] = line[sequence[i]];
    }

    count += std::strtoull(jolt, nullptr, 10);
  }

  printf("Result: %zu\n", count);
  return 0;
}

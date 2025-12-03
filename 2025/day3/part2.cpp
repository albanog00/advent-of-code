#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  uint64_t count = 0;
  std::string line;

  while (std::cin >> line) {
    uint64_t jolt = 0;
    size_t next = 0;

    for (size_t digit = 0; digit <= 11; ++digit) {
      size_t max = next;

      for (size_t i = max + 1; i < line.size() - (11 - digit); ++i) {
        if (line[i] > line[max]) {
          max = i;
        }
      }

      jolt = jolt * 10 + (line[max] - '0');
      next = max + 1;
    }

    count += jolt;
  }

  printf("Result: %zu\n", count);
  return 0;
}

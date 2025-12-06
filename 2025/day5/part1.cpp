#include <cstdint>
#include <cstdio>
#include <iostream>
#include <vector>

struct Range {
  uint64_t start;
  uint64_t end;
};

int main(int argc, char **argv) {
  std::string line;
  std::vector<Range> ranges;
  uint64_t start, end, count = 0;

  while (true) {
    std::getline(std::cin, line);
    if (line.empty())
      break;

    std::sscanf(line.c_str(), "%zu-%zu", &start, &end);
    ranges.push_back({start, end});
  }

  uint64_t id;
  while (std::cin >> id) {
    for (size_t i = 0; i < ranges.size(); ++i) {
      if (id >= ranges[i].start && id <= ranges[i].end) {
        count += 1;
        break;
      }
    }
  }

  printf("Result: %zu\n", count);
  return 0;
}

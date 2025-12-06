#include <algorithm>
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
  uint64_t count = 0;
  Range range;

  while (true) {
    std::getline(std::cin, line);
    if (line.empty())
      break;

    std::sscanf(line.c_str(), "%zu-%zu", &range.start, &range.end);
    ranges.push_back(range);
  }

  std::sort(ranges.begin(), ranges.end(),
            [](const Range &a, const Range &b) { return a.start < b.start; });

  size_t last = 0;
  std::vector<bool> removed(ranges.size(), false);
  for (size_t i = 1; i < ranges.size(); ++i) {
    if (ranges[i].start <= ranges[last].end) {
      ranges[last].end = std::max(ranges[i].end, ranges[last].end);
      removed[i] = true;
    } else {
      last = i;
    }
  }

  for (size_t i = 0; i < ranges.size(); ++i) {
    count += (ranges[i].end - ranges[i].start + 1) * !removed[i];
  }

  printf("Result: %zu\n", count);
  return 0;
}

#include <cassert>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <vector>

typedef std::vector<std::vector<uint64_t>> Cache;

uint64_t dfs(std::vector<std::string> &grid, Cache &cache, int currRow,
             int currCol) {
  if (currRow >= (int)grid.size() || currRow < 0 ||
      currCol >= (int)grid[0].size() || currCol < 0)
    return 0;

  if (cache[currRow][currCol])
    return cache[currRow][currCol];

  uint64_t result = 0;
  if (grid[currRow][currCol] == '^') {
    result = 1 + dfs(grid, cache, currRow + 1, currCol - 1) +
             dfs(grid, cache, currRow + 1, currCol + 1);
  } else {
    result = dfs(grid, cache, currRow + 1, currCol);
  }

  cache[currRow][currCol] = result;
  return cache[currRow][currCol];
}

int main(int argc, char **argv) {
  uint64_t count;
  std::vector<std::string> lines;
  std::string line;

  while (getline(std::cin, line)) {
    lines.push_back(line);
  }

  size_t rows = lines.size();
  size_t cols = lines[0].size();
  int startRow = 0, startCol = lines[0].find('S');

  Cache cache(rows, std::vector<uint64_t>(cols, 0));
  count = 1 + dfs(lines, cache, startRow, startCol);

  printf("Result: %zu\n", count);
  return 0;
}

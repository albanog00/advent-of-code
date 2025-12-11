#include <cassert>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <vector>

int dfs(std::vector<std::string> &grid, std::vector<std::vector<bool>> &visited,
        int currRow, int currCol) {
  if (currRow >= (int)grid.size() || currRow < 0 ||
      currCol >= (int)grid[0].size() || currCol < 0 ||
      visited[currRow][currCol])
    return 0;

  visited[currRow][currCol] = true;
  if (grid[currRow][currCol] == '^') {
    return 1 + dfs(grid, visited, currRow, currCol - 1) +
           dfs(grid, visited, currRow, currCol + 1);
  }

  return dfs(grid, visited, currRow + 1, currCol);
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

  std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
  count = dfs(lines, visited, startRow, startCol);

  printf("Result: %zu\n", count);
  return 0;
}

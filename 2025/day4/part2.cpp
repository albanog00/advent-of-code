#include <cstdint>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

const int directions[8][2] = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                              {1, 0},  {1, -1}, {0, -1}, {-1, -1}};

int countAdjacents(const std::vector<std::string> &grid, int row, int col) {
  int count = 0;
  int maxRow = grid.size() - 1;
  int maxCol = grid[0].size() - 1;

  for (const auto &dir : directions) {
    int currRow = row + dir[0];
    int currCol = col + dir[1];

    if ((currRow >= 0 && currRow <= maxRow) &&
        (currCol >= 0 && currCol <= maxCol)) {
      count += grid[currRow][currCol] == '@';
    }
  }

  return count;
}

int main(int argc, char **argv) {
  uint64_t initialState;
  uint64_t count = 0;
  std::vector<std::string> grid;
  std::string line;

  while (std::cin >> line) {
    grid.push_back(line);
  }

  while (true) {
    initialState = count;

    for (size_t row = 0; row < grid.size(); ++row) {
      for (size_t col = 0; col < grid[0].size(); ++col) {
        if (grid[row][col] == '@' && countAdjacents(grid, row, col) < 4) {
          grid[row][col] = '.';
          count += 1;
        }
      }
    }

    if (initialState == count)
      break;
  }

  printf("Result: %zu\n", count);
  return 0;
}

#include <cassert>
#include <charconv>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>

auto to_uint16_t = [](auto &&field) {
  uint16_t value = 0;
  std::from_chars(&*field.begin(), &*field.end(), value);
  return value;
};

int main(int argc, char **argv) {
  uint64_t count = 0;
  std::string line;
  std::vector<std::string> lines;
  std::vector<std::vector<uint16_t>> problems;

  while (getline(std::cin, line)) {
    lines.push_back(line);
  }

  for (size_t i = 0; i < lines.size() - 1; ++i) {
    problems.push_back(std::ranges::to<std::vector<uint16_t>>(
        std::string_view(lines[i]) | std::views::split(' ') |
        std::views::transform(to_uint16_t) |
        std::views::filter([](auto &&num) { return num != 0; })));
  }

  auto ops =
      std::string_view(*(lines.end() - 1)) | std::views::split(' ') |
      std::views::transform([](auto &&op) { return op.data()[0]; }) |
      std::views::filter([](auto &&op) { return op == '*' || op == '+'; }) |
      std::views::enumerate;

  for (const auto [col, op] : ops) {
    uint64_t totalCol = 1 * op == '*';
    for (size_t row = 0; row < problems.size(); ++row) {
      uint16_t num = problems[row][col];
      totalCol = totalCol * (op == '*' ? num : 1) + (op != '*' ? num : 0);
    }
    count += totalCol;
  }

  printf("Result: %zu\n", count);
  return 0;
}

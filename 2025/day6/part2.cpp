#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

typedef struct Token_t {
  uint16_t data[4];
  uint8_t len;
  char op;

} Token;

int main() {
  std::string line;
  std::vector<std::string> lines;

  while (getline(std::cin, line)) {
    lines.push_back(line);
  }

  std::vector<Token> problems;
  problems.reserve(lines.size());

  std::string vertical;
  std::string_view view;
  Token currentToken;
  size_t idx = 0;

  vertical.resize(lines.size());

  for (size_t i = 0; i < lines[0].size(); ++i) {
    bool isColumn = true;
    for (size_t j = 0; j < lines.size(); ++j) {
      vertical[j] = lines[j][i];
      isColumn &= vertical[j] == ' ';
    }

    if (isColumn) {
      currentToken.len = idx;
      problems.push_back(currentToken);
      idx = 0;

      continue;
    }

    view = vertical;

    if (view.back() != ' ') {
      currentToken.op = view.back();
    }

    uint16_t num = 0;
    for (size_t i = 0; i < 4; ++i)
      if (isdigit(view[i]))
        num = num * 10 + (view[i] - '0');
    currentToken.data[idx++] = num;
  }

  currentToken.len = idx;
  problems.push_back(currentToken);

  uint64_t count = 0;
  for (const auto &p : problems) {
    uint64_t total = 1 * p.op == '*';
    for (size_t i = 0; i < p.len; ++i) {
      total =
          total * (p.op == '*' ? p.data[i] : 1) + (p.op != '*' ? p.data[i] : 0);
    }
    count += total;
  }

  printf("Result: %zu\n", count);
  return 0;
}

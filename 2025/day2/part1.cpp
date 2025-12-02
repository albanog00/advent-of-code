#include <cstdint>
#include <cstdio>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  uint64_t start, end, count = 0;
  char trash;

  while (std::cin >> start >> trash >> end) {
    for (uint64_t i = start; i <= end; ++i) {
      std::string str = std::to_string(i);
      if ((str.size() & 1))
        continue;

      std::string_view view(str);
      int mid = view.size() / 2;
      bool invalid = view.substr(0, mid) == view.substr(mid, mid);
      count += (i * invalid);
    }
    std::cin >> trash;
  }

  printf("Result: %zu\n", count);
  return 0;
}

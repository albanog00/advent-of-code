#include <cstdint>
#include <cstdio>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  uint64_t start, end, count = 0;
  char trash;

  while (std::cin >> start >> trash >> end) {
    for (uint64_t id = start; id <= end; ++id) {
      std::string str = std::to_string(id);
      std::string_view view(str);
      size_t mid = view.size() / 2;

      bool loop = true;
      for (size_t windowSize = 1; (windowSize <= mid) & loop; ++windowSize) {
        if (view.size() % windowSize != 0)
          continue;

        bool valid = false;
        size_t parts = view.size() / windowSize;
        std::string_view window = view.substr(0, windowSize);

        for (size_t part = 1; part < parts; ++part) {
          size_t currentIndex = windowSize * part;
          valid |= (window != view.substr(currentIndex, windowSize));
        }

        count += (id * !valid);
        loop &= valid;
      }
    }
    std::cin >> trash;
  }

  printf("Result: %zu\n", count);
  return 0;
}

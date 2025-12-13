#include <cstdint>
#include <iostream>
#include <numeric>
#include <print>
#include <vector>

struct Vec3 {
  int64_t x, y, z;
};

struct Dist {
  size_t a, b;
  uint64_t d;

  bool operator<(const Dist &other) const { return d < other.d; }
  bool operator>(const Dist &other) const { return d > other.d; }
};

struct UnionFind {
  std::vector<uint64_t> parent;
  std::vector<uint64_t> size;

  UnionFind(size_t n) : parent(n), size(n, 1) {
    std::iota(parent.begin(), parent.end(), 0);
  }

  uint64_t find(uint64_t a) {
    if (parent[a] != a)
      parent[a] = find(parent[a]);
    return parent[a];
  }

  bool unite(uint64_t a, uint64_t b) {
    a = find(a);
    b = find(b);

    if (a == b)
      return false;
    if (size[a] < size[b])
      std::swap(a, b);

    parent[b] = a;
    size[a] += size[b];
    return true;
  }
};

uint64_t distance(const Vec3 &a, const Vec3 &b) {
  auto dx = a.x - b.x;
  auto dy = a.y - b.y;
  auto dz = a.z - b.z;
  return dx * dx + dy * dy + dz * dz;
}

int main(int argc, char **argv) {
  uint64_t count = 0;
  std::vector<Vec3> points;

  Vec3 point;
  char trash;
  while (std::cin >> point.x >> trash >> point.y >> trash >> point.z) {
    points.push_back(point);
  }

  size_t n = points.size();
  std::vector<Dist> distances;
  for (size_t i = 0; i < n; ++i) {
    const Vec3 &a = points[i];
    for (size_t j = i + 1; j < n; ++j) {
      const Vec3 &b = points[j];
      auto d = distance(a, b);
      distances.push_back({i, j, d});
    }
  }

  std::sort(distances.begin(), distances.end());

  UnionFind uf(n);
  size_t total = n, first = 0, second = 0;
  for (const auto &[a, b, d] : distances) {
    if (uf.unite(a, b)) {
      first = a;
      second = b;
      if (--total == 1)
        break;
    }
  }

  count = points[first].x * points[second].x;
  std::println("Result: {}", count);
  return 0;
}

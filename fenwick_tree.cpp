#include <cassert>
#include <vector>

class FenwickTree {
private:
  std::vector<long long> tree;
  int size;

public:
  // Initialize Fenwick Tree with 1-based indexing
  FenwickTree(int n) : size(n) { tree.assign(n + 1, 0); }

  // Point Update: Add 'delta' to element at 'index'
  void update(int index, long long delta) {
    assert(index > 0 && index <= size);
    for (; index <= size; index += index & -index) {
      tree[index] += delta;
    }
  }

  // Prefix Query: Returns sum of elements from 1 to 'index'
  long long query(int index) const {
    assert(index >= 0 && index <= size);
    long long sum = 0;
    for (; index > 0; index -= index & -index) {
      sum += tree[index];
    }
    return sum;
  }

  // Range Query: Returns sum in range [left, right]
  long long rangeQuery(int left, int right) const {
    assert(left > 0 && left <= right && right <= size);
    return query(right) - query(left - 1);
  }
};
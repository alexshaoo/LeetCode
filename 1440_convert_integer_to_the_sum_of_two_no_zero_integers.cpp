class Solution {
public:
  bool d(int a) {
    while (a > 0) {
      if (a%10==0) return false;
      a /= 10;
    }
    return true;
  }
  vector<int> getNoZeroIntegers(int n) {
    for (int i = 1; i <= n/2; ++i) {
      if (d(i) && d(n-i)) return {i, n-i};
    }
    return {};
  }
};
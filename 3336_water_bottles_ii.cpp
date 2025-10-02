class Solution {
public:
  int maxBottlesDrunk(int numBottles, int numExchange) {
    int ans = 0;
    int empty = 0, full = numBottles;
    while (full > 0 || empty >= numExchange) {
      // cout << full << ' ' << empty << ' ' << numExchange << '\n';
      ans += full;
      empty += full;
      full = 0;
      int cnt = 0, sm = 0;
      while (sm + numExchange <= empty) {
        ++cnt;
        sm += numExchange;
        ++numExchange;
      }
      full = cnt;
      empty -= sm;
    }
    return ans;
  }
};
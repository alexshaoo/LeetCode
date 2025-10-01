class Solution {
public:
  int numWaterBottles(int numBottles, int numExchange) {
    int cnt = 0;
    int filled = numBottles, empty = 0;
    while (filled > 0) {
      cnt += filled;
      empty += filled;
      filled = empty / numExchange;
      empty %= numExchange;
    }
    return cnt;
  }
};
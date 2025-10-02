class Solution {
public:
  int maxBottlesDrunk(int numBottles, int numExchange) {
    int cnt = numBottles;
    for (;numExchange<=numBottles;) {
      numBottles -= numExchange;
      ++numBottles;
      ++cnt;
      ++numExchange;
    }
    return cnt;
  }
};
class Solution {
public:
  int totalMoney(int n) {
    int mon = 0;
    int amt = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (i%7 == 0) {
        ++mon;
        amt = mon;
      } else {
        ++amt;
      }
      ans += amt;
    }
    return ans;
  }
};
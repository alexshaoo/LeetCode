class Solution {
public:
  int maximum69Number (int num) {
    int cur = 3, mul = 0;
    int ans = num;
    while (num > 0) {
      if (num % 10 == 6) mul = cur;
      num /= 10;
      cur *= 10;
    }
    return ans + mul;
  }
};
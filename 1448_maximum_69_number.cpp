class Solution {
public:
  int maximum69Number (int num) {
    for (int mul = 1e4; mul > 0; mul /= 10) {
      if ((num/mul)%10 == 6) {
        num += 3*mul;
        break;
      }
    }
    return num;
  }
};
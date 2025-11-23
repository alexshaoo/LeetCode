class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    long long tmp = x, rev = 0;
    while (x > 0) {
      rev = 10*rev + x%10;
      x /= 10;
    }
    return tmp == rev;
  }
};
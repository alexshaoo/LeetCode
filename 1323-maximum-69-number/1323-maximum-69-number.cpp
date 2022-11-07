class Solution {
public:
  int maximum69Number (int n) {
    int c = -1;
    int u = 0;
    int m = n;
    while (m) {
      if (m%10 == 6) {
        c = u;
      }
      m /= 10;
      ++u;
    }
    if (c == -1) {
      return n;
    }
    return n + 3*pow(10, c);
  }
};
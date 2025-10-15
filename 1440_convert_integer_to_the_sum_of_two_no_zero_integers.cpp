class Solution {
public:
  vector<int> getNoZeroIntegers(int n) {
    int a = 0, b = 0, p = 1;
    while (n > 0) {
      int d = n%10;
      if (d == 0) {
        a += p;
        b += 9*p;
        n = n/10-1;
      } else if (d == 1) {
        if (n == 1) {
          a += p;
          break;
        } else {
          a += 2*p;
          b += 9*p;
          n = n/10-1;
        }
      } else {
        a += p;
        b += (d-1)*p;
        n /= 10;
      }
      p *= 10;
    }
    return {a,b};
  }
};
class Solution {
public:
  int totalMoney(int n) {
    int w = n/7;
    int d = n%7;
    int ww = 7 * ((w + 3) * (w + 4) / 2 - 6);
    int dd = (w+d)*(w+d+1)/2 - w*(w+1)/2;
    return ww + dd;
  }
};
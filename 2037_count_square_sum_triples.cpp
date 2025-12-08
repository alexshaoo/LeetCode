class Solution {
public:
  int countTriples(int n) {
    vector<bool> square(2*n*n+1, false);
    for (int i = 1; i <= n; ++i) square[i*i] = true;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = i; j <= n; ++j) {
        if (square[i*i+j*j]) cnt += 2;
      }
    }
    return cnt;
  }
};
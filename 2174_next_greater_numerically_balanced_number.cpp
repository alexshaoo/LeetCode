class Solution {
public:
  bool f(int n) {
    vector<int> freq(10);
    while (n > 0) {
      freq[n%10]++;
      n /= 10;
    }
    for (int i = 0; i < 10; ++i) if (freq[i] != 0 && freq[i] != i) return false;
    return true;
  }
  int nextBeautifulNumber(int n) {
    while (!f(++n));
    return n;
  }
};
class Solution {
public:
  string findLexSmallestString(string s, int a, int b) {
    int n = s.length();
    vector<bool> vis(n);
    string ans = s;
    s = s+s;
    for (int i = 0; vis[i] == false; i = (i+b)%n) {
      vis[i] = true;
      for (int odd = 0; odd <= 9; ++odd) {
        for (int even = 0; even <= (b%2 ? 9 : 0); ++even) {
          string tmp = s.substr(i, n);
          for (int o = 1; o < n; o += 2) {
            tmp[o] = (tmp[o]-'0'+odd*a) % 10 + '0';
          }
          for (int e = 0; e < n; e += 2) {
            tmp[e] = (tmp[e]-'0'+even*a) % 10 + '0';
          }
          ans = min(ans, tmp);
        }
      }
    }
    return ans;
  }
};
class Solution {
public:
  int numSplits(string s) {
    int n = s.length();
    vector<int> l(26, 0), r(26, 0);
    int dl = 0, dr = 0;
    for (const char& c : s) {
      if (r[c-'a'] == 0) ++dr;
      r[c-'a']++;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      int idx = s[i]-'a';
      if (l[idx] == 0) ++dl;
      if (r[idx] == 1) --dr;
      l[idx]++;
      r[idx]--;
      cnt += (dl == dr);
    }
    return cnt;
  }
};
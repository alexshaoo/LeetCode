class Solution {
public:
  string removeDuplicates(string s) {
    int n = s.length();
    int i = 0;
    for (int j = 0; j < n; ++i, ++j) {
      s[i] = s[j];
      if (i > 0 && s[i-1] == s[i]) i -= 2;
    }
    return s.substr(0, i);
  }
};
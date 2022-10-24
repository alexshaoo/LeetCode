class Solution {
public:
  string mergeAlternately(string word1, string word2) {
    const int l1 = word1.size(), l2 = word2.size();
    const int t = min(l1, l2);
    string ans = "";
    for (int i = 0; i < t; ++i) {
      ans = ans + word1[i] + word2[i];
    }
    return ans + word1.substr(t, t-l1) + word2.substr(t, t-l2);
  }
};
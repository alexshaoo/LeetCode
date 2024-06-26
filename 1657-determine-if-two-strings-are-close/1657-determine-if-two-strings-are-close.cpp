class Solution {
public:
  bool closeStrings(string word1, string word2) {
    vector<int> f1(26), f2(26);
    for (char c : word1) ++f1[c-'a'];
    for (char c : word2) ++f2[c-'a'];
    return multiset(f1.begin(), f1.end()) == multiset(f2.begin(), f2.end()) && unordered_set(word1.begin(), word1.end()) == unordered_set(word2.begin(), word2.end());
  }
};
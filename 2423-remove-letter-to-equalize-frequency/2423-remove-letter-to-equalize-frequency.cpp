class Solution {
public:
  bool equalFrequency(string word) {
    int l = 0;
    int n = word.length();
    map<char, int> freq;
    for (const auto &i : word) freq[i]++;
    if (freq.size() == n) return 1;
    while (l <= n) {
      int c = 0;
      for(const auto &i : freq) {
        if (i.second < l) c += i.second;
        else c += (i.second-l);
      }
      if (c == 1) return true;
      l++;
    }
    return false;
  }
};
class Solution {
public:
  bool equalFrequency(string word) {
    const int l = word.size();
    for (int i = 0; i < l; i++) {
      map<char, int> freq;
      for (int j = 0; j < l; j++) {
        if (j == i) continue;
        else freq[word[j]]++;
      }
      set<int> s;
      for (const auto& thing : freq) s.insert(thing.second);
      if (s.size() == 1) return true;
    }
    return false;
  }
};
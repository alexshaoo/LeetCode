class Solution {
public:
  int canBeTypedWords(string text, string brokenLetters) {
    bool broken[26];
    for (const auto& ch : brokenLetters) broken[ch-'a'] = true;
    int cnt = 0;
    istringstream iss(text);
    string word;
    while (iss >> word) {
      bool b = false;
      for (const auto& ch : word) {
        if (broken[ch-'a']) {
          b = true;
          break;
        }
      }
      if (!b) ++cnt;
    }
    return cnt;
  }
};
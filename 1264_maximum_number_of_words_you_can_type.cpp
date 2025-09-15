class Solution {
public:
  int canBeTypedWords(string text, string brokenLetters) {
    bool broken[26];
    for (const auto& ch : brokenLetters) broken[ch-'a'] = true;
    int words = 0; // words you can type
    bool b = 0; 
    for (const auto& ch : text) {
      if (ch == ' ') {
        words += (b == 0);
        b = false;
      } else {
        b |= broken[ch-'a'];
      }
    }
    return words + (b == 0);
  }
};
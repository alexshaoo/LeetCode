class Solution {
public:
  bool doesAliceWin(string s) {
    string vowels = "aeiou";
    vector<bool> isVowel(26, false);
    for (char v : vowels) isVowel[v-'a'] = true;
    return any_of(s.begin(), s.end(), [&](char c) { 
      return isVowel[c-'a'];
    });
  }
};
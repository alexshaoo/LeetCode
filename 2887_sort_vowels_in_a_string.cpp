class Solution {
public:
  string sortVowels(string s) {
    vector<int> freq(128, 0);
    vector<bool> isVowel(128, false);
    string vowels = "AEIOUaeiou";
    for (char c : vowels) isVowel[c] = true;
    for (const char& c : s) {
      if (isVowel[c]) freq[c]++;
    }
    int i = 0;
    for (char& c : s) {
      if (isVowel[c]) {
        while (i < vowels.size() && freq[vowels[i]] == 0) ++i;
        c = vowels[i];
        --freq[vowels[i]];
      }
    }
    return s;
  }
};
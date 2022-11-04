class Solution {
public:
  string reverseVowels(string s) {
    int i = 0;
    int j = s.size()-1;
    string vowels = "aeiouAEIOU";
    while (i < j) {
      i = s.find_first_of(vowels, i);
      j = s.find_last_of(vowels, j);
      if (i < j) {
        swap(s[i++], s[j--]);
      }
    }
    return s;
  }
};
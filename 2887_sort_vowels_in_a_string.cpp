class Solution {
public:
  bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
  }
  string sortVowels(string s) {
    int n = s.length();
    vector<char> v;
    for (char c : s) {
      if (isVowel(c)) v.push_back(c);
    }
    sort(v.begin(), v.end());
    int i = 0;
    for (char& c : s) {
      if (isVowel(c)) {
        c = v[i];
        ++i;
      }
    }
    return s;
  }
};
class Solution {
public:
  int maxFreqSum(string s) {
    string vowels = "aeiou";
    vector<bool> isVowel(26, false);
    for (char v : vowels) isVowel[v-'a'] = true;
    map<char, int> v, c;
    for (char ch : s) {
      if (isVowel[ch-'a']) v[ch]++;
      else c[ch]++;
    }
    int vm = 0, cm = 0;
    for (auto& [ch, cnt] : v) {
      vm = max(vm, cnt);
    }
    for (auto& [ch, cnt] : c) {
      cm = max(cm, cnt);
    }
    return vm+cm;
  }
};
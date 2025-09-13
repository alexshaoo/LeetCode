class Solution {
public:
  int maxFreqSum(string s) {
    string vowels = "aeiou";
    vector<bool> isVowel(26, false);
    for (char v : vowels) isVowel[v-'a'] = true;
    unordered_map<char, int> mp;
    int vm = 0, cm = 0;
    for (const char& ch : s) {
      mp[ch]++;
      if (isVowel[ch-'a']) vm = max(vm, mp[ch]);
      else cm = max(cm, mp[ch]);
    }
    return vm+cm;
  }
};
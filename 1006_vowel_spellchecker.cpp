class Solution {
public:
  string f(string a, int (&isVowel)[26]) {
    a = l(a);
    for (auto& ch : a) {
      if (isVowel[ch-'a']) ch = '1';
    }
    return a;
  }
  string l(string a) {
    for (auto& ch : a) ch = tolower(ch);
    return a;
  }
  vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
    int n = wordlist.size();
    string vowels = "aeiou";
    int isVowel[26];
    for (const auto& v : vowels) isVowel[v-'a'] = true;
    vector<string> ans;
    unordered_set<string> s(wordlist.begin(), wordlist.end());
    unordered_map<string, string> mplower, mpvowel;
    for (const auto& w : wordlist) {
      string lower = l(w), converted = f(w, isVowel);
      mplower.insert({lower, w});
      mpvowel.insert({converted, w});
    }
    for (int i = 0; i < queries.size(); ++i) {
      string q = queries[i];
      if (s.count(q)) continue;
      string lower = l(q), converted = f(q, isVowel);
      if (mplower.count(lower)) {
        queries[i] = mplower[lower];
        continue;
      }
      if (mpvowel.count(converted)) {
        queries[i] = mpvowel[converted];
        continue;
      }
      queries[i] = "";
    }
    return queries;
  }
};
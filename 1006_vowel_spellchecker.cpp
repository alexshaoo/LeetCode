class Solution {
public:
  string f(string a, int (&isVowel)[26]) {
    string s = "";
    for (const auto& ch : a) {
      if (isVowel[ch-'a']) s += '1';
      else s += ch;
    }
    return s;
  }
  string l(string a, int d) {
    string s = "";
    for (const auto& c : a) {
      if (c >= 'A' && c <= 'Z') s += c+d;
      else s += c;
    }
    return s;
  }
  vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
    int n = wordlist.size();
    string vowels = "aeiou";
    int isVowel[26];
    int d = 'a'-'A';
    for (const auto& v : vowels) isVowel[v-'a'] = true;
    vector<string> ans;
    unordered_set<string> s;
    for (const auto& w : wordlist) s.insert(w);
    unordered_map<string, string> mplower, mpvowel;
    for (int i = 0; i < n; ++i) {
      string lower = l(wordlist[i], d);
      if (mplower.count(lower) == 0) mplower[lower] = wordlist[i];
      string converted = f(lower, isVowel);
      if (mpvowel.count(converted) == 0) mpvowel[converted] = wordlist[i];
    }
    unordered_map<string, string> mp;
    for (const auto& q : queries) {
      if (mp.contains(q)) {
        ans.push_back(mp[q]);
        continue;
      }
      if (s.count(q)) {
        ans.push_back(q);
        mp[q] = q;
        continue;
      }
      string qq = l(q, d);
      if (mplower.count(qq)) {
        ans.push_back(mplower[qq]);
        mp[qq] = mplower[qq];
        continue;
      }
      string qqq = f(qq, isVowel);
      if (mpvowel.count(qqq)) {
        ans.push_back(mpvowel[qqq]);
        mp[qqq] = mpvowel[qqq];
        continue;
      }
      ans.push_back("");
      mp[q] = "";
    }
    return ans;
  }
};
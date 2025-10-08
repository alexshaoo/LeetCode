class Solution {
public:
  vector<int> successfulPairs(vector<int>& spellss, vector<int>& potions, long long success) {
    vector<pair<int, int>> spells(spellss.size());
    int sl = spells.size(), pl = potions.size();
    for (int i = 0; i < sl; ++i) spells[i] = {spellss[i], i};
    sort(spells.begin(), spells.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
      return a.first > b.first;
    });
    sort(potions.begin(), potions.end());
    vector<int> ans(sl);
    int si = 0, pi = 0;
    while (si < sl && pi < pl) {
      while (pi < pl && (long long)spells[si].first * potions[pi] < success) ++pi;
      if (pi == pl) return ans;
      ans[spells[si].second] = pl-pi;
      ++si;
    }
    return ans;
  }
};
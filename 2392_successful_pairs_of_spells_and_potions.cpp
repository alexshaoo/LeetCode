class Solution {
public:
  vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    sort(potions.begin(), potions.end());
    vector<int> ans;
    for (int s : spells) {
      auto it = lower_bound(potions.begin(), potions.end(), (success + s-1)/ s);
      ans.push_back(potions.end() - it);
    }
    return ans;
  }
};
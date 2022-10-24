class Solution {
public:
  int maxLength(vector<string>& arr) {
    vector<bitset<26>> dp = {bitset<26>()};
    int res = 0;
    
    // input dupes
    for (const auto& s : arr) {
      bitset<26> a;
      for (const auto& c : s) a.set(c - 'a');
      if (a.count() < s.size()) continue;
    
      // bitop
      for (int i = 0; i < dp.size(); ++i) {
        if ((dp[i] & a).any()) continue;
        dp.push_back(dp[i] | a);
        res = max(res, (int)dp[i].count() + (int)a.count());
      }
    }
    
    return res;
  }
};
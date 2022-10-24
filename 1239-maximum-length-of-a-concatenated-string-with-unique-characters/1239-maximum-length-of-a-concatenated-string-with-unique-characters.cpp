class Solution {
public:
  int maxLength(vector<string>& arr) {
    // vector of one empty bitset initially so the first element in arr is automatically added
    vector<bitset<26>> dp = {bitset<26>()};
    int res = 0;
    
    // input dupes
    for (const auto& s : arr) {
      bitset<26> next;
      for (const auto& c : s) next.set(c - 'a');
      if (next.count() < s.size()) continue;
    
      // bitop
      for (int i = 0; i < dp.size(); ++i) {
        bitset curr = dp[i];
        if ((curr & next).any()) continue;
        dp.push_back(curr | next);
        res = max(res, (int)(curr.count() + next.count()));
      }
    }
    
    return res;
  }
};
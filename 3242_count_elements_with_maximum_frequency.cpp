class Solution {
public:
  int maxFrequencyElements(vector<int>& nums) {
    unordered_map<int, int> mp;
    int mx = 0;
    for (int num : nums) {
      mp[num]++;
      mx = max(mx, mp[num]);
    }
    int c = 0;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
      if (it->second == mx) ++c;
    }
    return c * mx;
  }
};
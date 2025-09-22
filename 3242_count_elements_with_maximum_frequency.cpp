class Solution {
public:
  int maxFrequencyElements(vector<int>& nums) {
    unordered_map<int, int> mp;
    for (int num : nums) {
      mp[num]++;
    }
    int mx = 0;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
      mx = max(mx, it->second);
    }
    int ans = 0;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
      if (it->second == mx) ans++;
    }
    return ans * mx;
  }
};
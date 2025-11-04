class Solution {
public:
  vector<int> findXSum(vector<int>& nums, int k, int x) {
    int n = nums.size();
    auto cmp = [&](const pair<int, int>& a, const pair<int, int>& b) {
      if (a.second == b.second) return a.first > b.first;
      return a.second > b.second;
    };
    vector<int> ans(n-k+1);
    for (int i = 0; i <= n-k; ++i) {
      unordered_map<int, int> freq;
      for (int j = 0; j < k; ++j) freq[nums[i+j]]++;
      vector<pair<int, int>> v(freq.begin(), freq.end());
      sort(v.begin(), v.end(), cmp);
      for (int j = 0; j < min(x, (int)v.size()); ++j) {
        ans[i] += v[j].first * v[j].second;
      }
    }
    return ans;
  }
};
class Solution {
public:
  int maxFrequency(vector<int>& nums, int k, int numOperations) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;
    int l = 0, r = 0;
    int ans = 0;
    set<int> s;
    for (int num : nums) {
      s.insert(num-k);
      s.insert(num);
      s.insert(num+k+1);
    }
    for (const auto& num : s) {
      while (r < n && num+k >= nums[r]) ++r;
      while (l < r && num-k > nums[l]) ++l;
      ans = max(ans, min(r-l, freq[num]+numOperations));
    }
    return ans;
  }
};
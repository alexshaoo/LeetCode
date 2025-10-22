class Solution {
public:
  int maxFrequency(vector<int>& nums, int k, int numOperations) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    unordered_map<long long, long long> freq;
    for (long long num : nums) freq[num]++;
    long long l = 0, r = 0;
    long long ans = 0;
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
    return (int)ans;
  }
};
class Solution {
public:
  int maxFrequency(vector<int>& nums, int k, int numOperations) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;
    int l = 0, r = 0;
    int ans = 0;
    for (int num = nums[0]-k; num <= nums[n-1]+k; ++num) {
      while (r < n-1 && num+k >= nums[r+1]) ++r;
      while (l <= r && num-k > nums[l]) ++l;
      if (r-l+1-freq[num] > numOperations) ans = max(ans, freq[num]+numOperations);
      else ans = max(ans, r-l+1);
    }
    return ans;
  }
};
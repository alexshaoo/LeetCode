class Solution {
public:
  int maxIncreasingSubarrays(vector<int>& nums) {
    int n = nums.size();
    int currLen = 1, prevLen = 0;
    int ans = 0;
    for (int i = 1; i < n; ++i) {
      if (nums[i] <= nums[i-1]) {
        prevLen = currLen;
        currLen = 1;
      } else {
        ++currLen;
      }
      ans = max(ans, min(prevLen, currLen));
      ans = max(ans, currLen/2);
    }
    return ans;
  }
};
class Solution {
public:
  int maxIncreasingSubarrays(vector<int>& nums) {
    const int MIN = -(1e9+5);
    nums.push_back(MIN);
    int last = MIN, currLen = 0, prevLen = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] <= last) {
        ans = max(ans, min(prevLen, currLen));
        ans = max(ans, currLen/2);
        prevLen = currLen;
        currLen = 1;
      } else {
        ++currLen;
      }
      last = nums[i];
    }
    return ans;
  }
};
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int zeroCount = 0;
        int l = 0;
        for (int r = 0; r < n; ++r) {
            zeroCount += (nums[r] == 0);
            while (zeroCount > 1) {
                zeroCount -= (nums[l] == 0);
                ++l;
            }
            ans = max(ans, r-l);
        }
        return ans;
    }
};
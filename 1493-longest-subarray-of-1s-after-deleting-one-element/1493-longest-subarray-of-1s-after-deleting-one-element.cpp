class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // dp[k][d] stores current length of 1s
        // up to elemnt k, 0 means not deleted yet, 1 means deleted
        int n = nums.size();
        int zeroCount = 0;
        int ans = 0;
        int l = 0;
        bool zero = false;
        for (int r = 0; r < n; ++r) {
            if (nums[r] == 0) {
                ++zeroCount;
                zero = true;
            }
            while (zeroCount > 1) {
                zeroCount -= (nums[l] == 0);
                ++l;
            }
            if (zeroCount == 1) {
                ans = max(ans, r-l);
            }
        }
        return zero ? ans : n-1;
    }
};
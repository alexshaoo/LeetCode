class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int mn = -1, mx = -1, inv = -1;
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < minK || nums[i] > maxK) inv = i;
            if (nums[i] == minK) mn = i;
            if (nums[i] == maxK) mx = i;
            ans += max(min(mn, mx) - inv, 0);
        }
        return ans;
    }
};
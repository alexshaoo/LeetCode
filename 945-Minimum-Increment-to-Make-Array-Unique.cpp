class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int prev = nums[0];
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            while (nums[i] <= prev) {
                ++ans;
                ++nums[i];
            }
            prev = nums[i];
        }
        return ans;
    }
};
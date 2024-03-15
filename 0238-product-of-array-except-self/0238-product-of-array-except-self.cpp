class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long all = 1;
        int numZeroes = 0; 
        for (const auto& num : nums) {
            if (num == 0) ++numZeroes;
            else all *= num;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (numZeroes >= 2) {
                nums[i] = 0;
            } else if (numZeroes == 1) {
                if (nums[i] == 0) nums[i] = all;
                else nums[i] = 0;
            } else {
                nums[i] = all / nums[i];
            }
        }
        return nums;
    }
};
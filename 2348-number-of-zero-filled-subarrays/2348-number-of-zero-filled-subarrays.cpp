class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0, cnt = 0;
        for (int num : nums) {
            if (num == 0) ++cnt;
            else cnt = 0;
            ans += cnt;
        }
        return ans;
    }
};
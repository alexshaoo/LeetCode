class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        nums.push_back(-1);
        int n = nums.size();
        long long ans = 0, cnt = 0;
        for (int num : nums) {
            if (num != 0 && cnt != 0) {
                ans += cnt * (cnt+1) / 2;
                cnt = 0;
            }
            if (num == 0) ++cnt;
        }
        // ans += cnt * (cnt+1) / 2;
        return ans;
    }
};
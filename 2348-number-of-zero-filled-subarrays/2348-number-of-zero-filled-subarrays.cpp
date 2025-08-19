class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        long long ans = 0;
        while (l < n && nums[l] != 0) ++l;
        while (l < n) {
            r = l;
            while (r < n && nums[r] == 0) ++r;
            --r;
            long long len = r-l+1;
            ans += ((len) * (len+1)) / 2;
            l = r+1;
            while (l < n && nums[l] != 0) ++l;
        }
        return ans;
    }
};
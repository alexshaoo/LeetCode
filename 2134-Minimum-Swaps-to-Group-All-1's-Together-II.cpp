class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int tot = accumulate(nums.begin(), nums.end(), 0, plus<int>());
        // cout << tot << '\n';
        for (int i = 0; i < n; ++i) nums.push_back(nums[i]);
        int c = 0;
        for (int i = 0; i < tot; ++i) {
            if (nums[i] == 0) ++c;
        }
        int ans = c;
        for (int i = 0; i < n; ++i) {
            c -= (nums[i] == 0);
            c += (nums[i+tot] == 0);
            ans = min(ans, c);
        }
        return ans;
    }
};
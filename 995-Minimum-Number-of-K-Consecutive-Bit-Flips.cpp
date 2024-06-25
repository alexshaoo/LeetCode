class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int flips = 0;
        for (int i = 0; i < n; ++i) {
            if (i >= k && nums[i-k] == -1) --flips; 
            bool flipped = flips % 2 == 1;
            // cout << flipped << '\n';
            if (i > n-k && nums[i] ^ flipped == 0) return -1;
            if (i <= n-k && nums[i] ^ flipped == 0) {
                nums[i] = -1;
                ++flips;
                ++ans;
            }
            // cout << i << ' ' << flips << ' ' << ans << '\n';
        }
        return ans;
    }
};
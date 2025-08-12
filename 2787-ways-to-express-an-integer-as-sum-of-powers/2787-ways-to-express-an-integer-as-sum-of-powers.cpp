class Solution {
public:
    static int constexpr MOD = 1e9+7;
    int f(vector<vector<int>>& dp, int remainingSum, int num, int x) {
        if (remainingSum < 0 || remainingSum < pow(num, x)) return 0;
        if (remainingSum == pow(num, x)) return 1;
        if (remainingSum >= 0 && remainingSum < dp.size() && num >= 0 && num < dp.size()) {
            if (dp[remainingSum][num] != -1) return dp[remainingSum][num];
        }
        // cout << remainingSum << ' ' << num << ' ' << pow(num, x) << '\n';
        int newRemainingSum = remainingSum - pow(num, x);
        dp[remainingSum][num] = 0;
        for (int i = num-1; i > 0; --i) {
            dp[remainingSum][num] = (dp[remainingSum][num] + f(dp, newRemainingSum, i, x)) % MOD;
        }
        return dp[remainingSum][num];
    }
    int numberOfWays(int n, int x) {
        // dp[remainingSum][num] = the number of ways to make remainingSum given that num is the biggest integer in our set
        // dp[10][3] = dp[1][2] + dp[1][1] = 0 + 1
        // ans is dp[n][1:n]
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = (ans + f(dp, n, i, x)) % MOD;
        }
        return ans;
    }
};
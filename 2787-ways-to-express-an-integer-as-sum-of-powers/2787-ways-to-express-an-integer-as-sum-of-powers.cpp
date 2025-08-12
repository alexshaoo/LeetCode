class Solution {
public:
    static int constexpr MOD = 1e9+7;
    // int f(vector<vector<int>>& dp, int remainingSum, int num, int x, long long p) {
    //     if (remainingSum < 0 || (long long)remainingSum < p) return 0;
    //     if (remainingSum == p) return 1;
    //     if (remainingSum >= 0 && remainingSum < dp.size() && num >= 0 && num < dp.size()) {
    //         if (dp[remainingSum][num] != -1) return dp[remainingSum][num];
    //     }
    //     // cout << remainingSum << ' ' << num << ' ' << pow(num, x) << '\n';
    //     long long newRemainingSum = (long long)remainingSum - p;
    //     dp[remainingSum][num] = 0;
    //     for (int i = num-1; i > 0; --i) {
    //         dp[remainingSum][num] = (dp[remainingSum][num] + f(dp, (int)newRemainingSum, i, x, (long long)pow(i, x))) % MOD;
    //     }
    //     return dp[remainingSum][num];
    // }
    int numberOfWays(int n, int x) {
        // dp[remainingSum][num] = the number of ways to make remainingSum given that num is the biggest integer in our set
        // dp[10][3] = dp[1][2] + dp[1][1] = 0 + 1
        // ans is dp[n][1:n]
        int mx = 1;
        while (pow(mx+1, x) <= n) ++mx;
        vector<vector<long long>> dp(n+1, vector<long long>(mx+1, 0));
        for (int i = 0; i <= mx; ++i) {
            dp[0][i] = 1;
        }
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 0;
        }
        for (int remainingSum = 1; remainingSum <= n; ++remainingSum) {
            for (int maxNum = mx; maxNum > 0; --maxNum) {
                long long newReaminingSum = remainingSum - pow(maxNum, x);
                if (newReaminingSum <= 0) {
                    if (newReaminingSum == 0) dp[remainingSum][maxNum] = 1;
                    continue;
                }
                for (int num = maxNum-1; num > 0; --num) {
                    dp[remainingSum][maxNum] = (dp[remainingSum][maxNum] + dp[newReaminingSum][num]) % MOD;
                }
            }
        }
        // for (auto a : dp) {
        //     for (auto b : a) {
        //         cout << b << ' ';
        //     }
        //     cout << '\n';
        // }
        long long ans = 0;
        for (int i = 1; i <= mx; ++i) {
            ans = (ans + dp[n][i]) % MOD;
        }
        return (int)ans;
    }
};
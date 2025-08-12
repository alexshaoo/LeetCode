class Solution {
public:
    static int constexpr MOD = 1e9+7;
    int numberOfWays(int n, int x) {
        // dp[i][j] means number of ways to use first i integers to form sum j
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            long long p = pow(i, x);
            for (int j = n; j >= 0; --j) {
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            }
            for (int j = n; j >= 0; --j) {
                if (j-p < 0) break;
                dp[i][j] = (dp[i][j] + dp[i-1][j-p]) % MOD;
            }
        }
        // for (auto a : dp) {
        //     for (auto b : a) cout << b << ' ';
        //     cout << '\n';
        // }
        return dp[n][n];
    }
};
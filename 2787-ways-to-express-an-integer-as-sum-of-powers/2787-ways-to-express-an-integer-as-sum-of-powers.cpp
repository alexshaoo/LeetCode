class Solution {
public:
    static int constexpr MOD = 1e9+7;
    int numberOfWays(int n, int x) {
        // dp[i][j] means number of ways to use first i integers to form sum j
        vector<vector<int>> dp;
        vector<int> init(n+1, 0);
        dp.push_back(init);
        dp[0][0] = 1;
        vector<long long> pows(n+1);
        for (int p = 0; p <= n; ++p) {
            long long val = 1;
            for (int _ = 0; _ < x; ++_) val *= p;
            pows[p] = val;
        }
        for (int i = 1; i <= n; ++i) {
            long long p = pows[i];
            dp.push_back(dp.back());
            for (int j = n; j >= 0; --j) {
                if (j-p < 0) break;
                dp[i][j] = (dp[i][j] + dp[i-1][j-p]) % MOD;
            }
        }
        return dp[n][n];
    }
};
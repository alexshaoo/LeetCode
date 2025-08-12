class Solution {
public:
    static int constexpr MOD = 1e9+7;
    int numberOfWays(int n, int x) {
        // dp[i] is the number of ways to make i uniquely
        vector<int> pows, dp(n+1, 0);
        dp[0] = 1;
        for (int a = 1; ; ++a) {
            long long p = 1;
            for (int k = 0; k < x; ++k) {
                p *= a;
                if (p > n) break;
            }
            if (p > n) break;
            pows.push_back((int)p);
        }
        for (int p : pows) {
            for (int sm = n; sm >= p; --sm) {
                int val = dp[sm-p];
                if (val > 0) {
                    dp[sm] = (dp[sm] + val) % MOD;
                }
            }
        }
        return dp[n];
    }
};
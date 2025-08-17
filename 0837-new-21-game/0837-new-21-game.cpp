class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k + maxPts <= n || k == 0) return 1.0;
        vector<double> dp(n+1, 0);
        dp[0] = 1;
        double sm = 1, ans = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = sm / maxPts;
            if (i < k) sm += dp[i];
            else ans += dp[i];
            if (i >= maxPts) sm -= dp[i-maxPts];
        }
        return ans;
    }
};
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        // n = 21, k = 17, maxPts = 10
        // cur = 16 -> [17, 26]
        vector<double> dp(n+1, 0);
        dp[0] = 1;
        double sm = 0;
        for (int i = 1; i <= n; ++i) {
            int l = max(0, i-maxPts);
            int r = min(i-1, k-1);
            if (i <= k) sm += dp[i-1] / maxPts;
            if (i-maxPts-1 >= 0 && i-maxPts-1 < k) sm -= dp[i-maxPts-1] / maxPts;
            dp[i] = sm;
        }
        double ans = 0;
        for (int i = k; i <= n; ++i) ans += dp[i];
        // for (double a : dp) cout << a << ' ';
        return ans;
    }
};
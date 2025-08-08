class Solution {
public:
    static const int MAX_SZ = 200;
    double dp[MAX_SZ][MAX_SZ];
    double calc(int n, int m) { // in units (rounded up multiples of 25)
        if (n <= 0 && m <= 0) return 0.5;
        if (n > 0 && m <= 0) return 0.0;
        if (n <= 0 && m > 0) return 1.0;
        double a, b, c, d;
        if (dp[n][m] != -1) return dp[n][m];
        double p = 0.25*calc(n-4, m) + 0.25*calc(n-3, m-1) + 0.25*calc(n-2, m-2) + 0.25*calc(n-1, m-3);
        dp[n][m] = p;
        return p;
    }
    double soupServings(int n) {
        if (n > 4825) return 1.0;
        int units = ceil(n/25.0);
        fill(&dp[0][0], &dp[0][0] + MAX_SZ*MAX_SZ, -1.0);
        return calc(units, units);
    }
};
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // sum of squares = n * (n+1) * (2n+1) / 6
        // 1^2 + 2^2 + ... + n^2 = S
        // 1^2 + 2^2 + ... + (n-1)^2 = S
        // (k + 1)^3 - k^3 = 3k^2 + 3k + 1
        // sum of ((k + 1)^3 - k^3) = sum of (3k^2 + 3k + 1) 
        // (n + 1)^3 - 1 = 3 sum(k^2) + 3 sum(k) + n
        // 3 sum(k^2) = (n + 1)^3 - 3 sum(k) - n - 1 = n^3 + 3n^2 + 3n - 3(n(n+1))/2 - n
        // = n^3 + 3n^2 + 2n - (3/2)(n^2 + n) = (2n^3 + 6n^2 + 4n - 3n^2 - 3n) / 2 = (2n^3 + 3n^2 + n) / 2
        // sum(k^2) = n(n+1)(2n+1)/6
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (matrix[i-1][j-1] == 0) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                ans += dp[i][j];
            }
        }
        return ans;
    }
};
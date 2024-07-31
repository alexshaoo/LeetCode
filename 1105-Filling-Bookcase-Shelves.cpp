class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int dp[1005];
        memset(dp, 1000005, sizeof(dp));
        dp[0] = 0;
        int n = books.size();
        for (int i = 1; i <= n; ++i) {
            int k = 0, w = 0, h = 0;
            while (k < i && w <= shelfWidth - books[i-k-1][0]) {
                h = max(h, books[i-k-1][1]);
                // cout << i-k-1 << ' ' << dp[i-k-1] << ' ' << h << '\n';
                dp[i] = min(dp[i], dp[i-k-1] + h);
                w += books[i-k-1][0];
                ++k;
            }
            // cout << "i is " << i << ", dp[i]: " << dp[i] << '\n';
        }
        return dp[n];
    }
};
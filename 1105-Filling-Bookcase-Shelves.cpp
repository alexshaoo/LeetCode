class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int dp[1005];
        memset(dp, 1000005, sizeof(dp));
        dp[0] = 0;
        int n = books.size();
        for (int i = 1; i <= n; ++i) {
            int k = 1, w = 0, h = 0;
            while (k <= i) {
                h = max(h, books[i-k][1]);
                w += books[i-k][0];
                if (w > shelfWidth) break;
                dp[i] = min(dp[i], dp[i-k] + h);
                ++k;
            }
        }
        return dp[n];
    }
};
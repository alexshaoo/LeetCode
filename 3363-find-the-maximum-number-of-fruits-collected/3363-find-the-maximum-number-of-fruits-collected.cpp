class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int diag = 0;
        int n = fruits.size();
        auto bounds = [&](int r, int c) -> bool {
            return (r >= 0 && r < n && c >=0 && c < n);
        };
        // 0, 0
        for (int i = 0; i < n; ++i) diag += fruits[i][i];
        // 0, n-1
        vector<vector<int>> dp1(n, vector<int>(n, 0));
        vector<vector<int>> dirs1 = {{-1, -1}, {-1, 0}, {-1, 1}};
        for (int r = 0; r < n-1; ++r) {
            for (int c = n-1-r; c < n; ++c) {
                int mx = 0;
                for (auto dir : dirs1) {
                    if (bounds(r+dir[0], c+dir[1])) mx = max(mx, dp1[r+dir[0]][c+dir[1]]);
                }
                dp1[r][c] = fruits[r][c] + mx;
            }
        }
        // n-1, 0
        vector<vector<int>> dp2(n, vector<int>(n, 0));
        vector<vector<int>> dirs2 = {{1, -1}, {0, -1}, {-1, -1}};
        for (int c = 0; c < n-1; ++c) {
            for (int r = n-1-c; r < n; ++r) {
                int mx = 0;
                for (auto dir : dirs2) {
                    if (bounds(r+dir[0], c+dir[1])) mx = max(mx, dp2[r+dir[0]][c+dir[1]]);
                }
                dp2[r][c] = fruits[r][c] + mx;
            }
        }
        return diag + dp1[n-2][n-1] + dp2[n-1][n-2];
    }
};
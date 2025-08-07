class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int diag = 0;
        int n = fruits.size();
        auto bounds = [&](int r, int c) -> bool {
            return (r >= 0 && r < n && c >=0 && c < n);
        };
        // 0, 0
        for (int i = 0; i < n; ++i) {
            diag += fruits[i][i];
            fruits[i][i] = 0;
        }
        fruits[n-1][n-1] = diag;
        // n-1, 0
        for (int c = 0; c < n-1; ++c) {
            for (int r = c+1; r < n; ++r) {
                if (c < n-1-r) {
                    fruits[r][c] = 0;
                } else { 
                    if (c != 0) fruits[r][c] += max(fruits[r-1][c-1], max(fruits[r][c-1], (r==n-1 ? 0 : fruits[r+1][c-1])));
                }
            }
        }
        // 0, n-1
        for (int r = 0; r < n-1; ++r) {
            for (int c = r+1; c < n; ++c) {
                if (r < n-1-c) {
                    fruits[r][c] = 0;
                } else { 
                    if (r != 0) fruits[r][c] += max(fruits[r-1][c-1], max(fruits[r-1][c], (c==n-1 ? 0 : fruits[r-1][c+1])));
                }
            }
        }
        return diag + fruits[n-2][n-1] + fruits[n-1][n-2];
    }
};
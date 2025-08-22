class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        int n = grid.size(), m = grid[0].size();
        int l = m, r = -1, u = n, d = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    l = min(l, j);
                    r = max(r, j);
                    u = min(u, i);
                    d = max(d, i);
                }
            }
        }
        return (r-l+1) * (d-u+1);
    }
};
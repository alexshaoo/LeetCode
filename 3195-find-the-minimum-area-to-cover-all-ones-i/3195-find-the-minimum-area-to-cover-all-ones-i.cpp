class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<bool> rowHasOne(n), colHasOne(m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    rowHasOne[i] = true;
                    break;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[j][i]) {
                    colHasOne[i] = true;
                    break;
                }
            }
        }
        // for (bool r : rowHasOne) cout << r << ' ';
        // cout << '\n';
        // for (bool r : colHasOne) cout << r << ' ';
        // cout << '\n';
        int l = 0, r = m-1;
        while (!colHasOne[l]) ++l;
        while (!colHasOne[r]) --r;
        int u = 0, d = n-1;
        while (!rowHasOne[u]) ++u;
        while (!rowHasOne[d]) --d;
        return (r-l+1) * (d-u+1);
    }
};
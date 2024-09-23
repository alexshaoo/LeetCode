class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int ans = 0;
        auto inBounds = [n, m](int r, int c) {
            return 0 <= r && r < n && 0 <= c && c < m;
        };
        function<void(int, int)> dfs = [&](int r, int c) {
            if (!inBounds(r, c) || vis[r][c] || grid[r][c] == '0') return;
            vis[r][c] = true;
            vector<pair<int, int>> dirs = {
                {0, -1},
                {0, 1},
                {-1, 0},
                {1, 0}
            };
            for (const auto& dir : dirs) {
                dfs(r + dir.first, c + dir.second);
            }
        };
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    dfs(i, j);
                    ++ans;
                }
            }
        }
        return ans;
    }
};
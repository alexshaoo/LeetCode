class Solution {
public:
    bool inBounds(int r, int c, int n, int m) {
        return r >= 0 && r < n && c >= 0 && c < m;
    }
    vector<pair<int, int>> dirs = {
        {0, -1},
        {0, 1},
        {-1, 0},
        {1, 0}
    };
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int r, int c) {
        // cout << r << ' ' << c << '\n';
        int fish = grid[r][c];
        vis[r][c] = true;
        for (const auto& [dr, dc] : dirs) {
            if (inBounds(r+dr, c+dc, grid.size(), grid[0].size()) && !vis[r+dr][c+dc]) {
                fish += dfs(grid, vis, r+dr, c+dc);
            }
        }
        return fish;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 0) vis[i][j] = true;
            }
        }
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (!vis[i][j]) {
                    
                    int t = dfs(grid, vis, i, j);
                    // cout <<t << '\n';
                    ans = max(ans, t);
                }
            }
        }
        return ans;
    }
};
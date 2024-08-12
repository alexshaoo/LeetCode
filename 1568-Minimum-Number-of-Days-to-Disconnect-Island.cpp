class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, pair<int, int> p) {
        int n = grid.size(), m = grid[0].size();
        deque<pair<int, int>> dq = {p};
        vector<pair<int, int>> dir = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };
        while (!dq.empty()) {
            auto[i, j] = dq.front();
            dq.pop_front();
            for (const auto& d : dir) {
                int r = i + d.first;
                int c = j + d.second;
                if (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1 && !vis[r][c]) {
                    vis[r][c] = true;
                    dq.push_back(make_pair(r, c));
                }
            }
        }
    }
    int f(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int c = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    dfs(grid, vis, make_pair(i, j));
                    ++c;
                }
            }
        }
        return c;
    }
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (f(grid) != 1) return 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (f(grid) != 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};

class Solution {
public:
    const vector<pair<int, int>> directions = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };
    int bfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        grid2[i][j] = 0;
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < m; ++j) {
        //         cout << grid2[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        bool good = grid1[i][j] == 1;
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (const auto& d : directions) {
                int nr = r + d.first, nc = c + d.second;
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid2[nr][nc] == 1) {
                    if (grid1[nr][nc] == 0) good = false;
                    grid2[nr][nc] = 0;
                    q.push({nr, nc});
                }
            }
        }
        // if (good) cout << i << ' ' << j << '\n';
        return good;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m = grid1[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid2[i][j] == 1) {
                    ans += bfs(i, j, grid1, grid2);
                }
            }
        }
        return ans;
    }
};

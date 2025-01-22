class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<pair<int, int>> waters;
        vector<vector<bool>> vis(n, vector<bool>(m));
        vector<vector<int>> heights(n, vector<int>(m));
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (isWater[i][j] == 1) {
                    waters.push_back({i, j});
                    vis[i][j] = true;
                    ++cnt;
                }
            }
        }
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        auto inBounds = [&](int r, int c) -> bool {
            return r >= 0 && r < n && c >= 0 && c < m && !vis[r][c];
        };
        while (cnt < n*m) {
            vector<pair<int, int>> newWaters;
            for (auto [r, c] : waters) {
                for (auto [dr, dc] : dirs) {
                    int nr = r+dr;
                    int nc = c+dc;
                    if (inBounds(nr, nc)) {
                        vis[nr][nc] = true;
                        heights[nr][nc] = heights[r][c] + 1;
                        newWaters.push_back({nr, nc});
                        ++cnt;
                    }
                }
            }
            waters = newWaters;
        }
        return heights;
    }
};
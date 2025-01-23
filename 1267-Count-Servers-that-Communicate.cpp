class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> rows(n), cols(m);
        vector<pair<int, int>> servers;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    rows[i]++;
                    cols[j]++;
                    servers.push_back({i, j});
                }
            }
        }
        int iso = 0;
        for (const auto& [r, c] : servers) {
            if (rows[r] == 1 && cols[c] == 1) ++iso;
        }
        return servers.size() - iso;
    }
};
class Solution {
public:
    vector<vector<int>> dirs = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}, {-1, -1}}; // indices 1-4 are dirs
    int backtrack(vector<vector<int>>& grid, int r, int c, int numToMatch, int dir, bool turned) {
        if (!(r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] == numToMatch)) {
            return 1;
        }
        int right = 0;
        if (!turned) {
            right = backtrack(grid, r + dirs[dir+1][0], c + dirs[dir+1][1], 2-numToMatch, dir+1, true);
        }
        int straight = backtrack(grid, r + dirs[dir][0], c + dirs[dir][1], 2-numToMatch, dir, turned);
        return 1 + max(straight, right);
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    for (int d = 0; d < 4; ++d)
                        ans = max(ans, backtrack(grid, i+dirs[d][0], j+dirs[d][1], 2, d, false));
                }
            }
        }
        return ans;
    }
};
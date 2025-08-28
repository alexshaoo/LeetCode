class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int d = 0; d < n; ++d) {
            vector<int> diag;
            for (int r = 0; r < n-d; ++r) {
                diag.push_back(grid[r+d][r]);
            }
            sort(diag.begin(), diag.end(), [](const int& a, const int& b) {
                return a >= b;
            });
            for (int r = 0; r < n-d; ++r) {
                grid[r+d][r] = diag[r];
            }
        }
        for (int d = 1; d < n; ++d) {
            vector<int> diag;
            for (int r = 0; r < n-d; ++r) {
                diag.push_back(grid[r][r+d]);
            }
            sort(diag.begin(), diag.end());
            for (int r = 0; r < n-d; ++r) {
                grid[r][r+d] = diag[r];
            }
        }
        return grid;
    }
};
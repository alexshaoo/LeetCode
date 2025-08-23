class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<pair<int, int>> s;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) s.insert({i, j});
            }
        }
        function<int(set<pair<int,int>>, int)> f = [&](set<pair<int, int>> s, int k) -> int { // smallest area for k rectanges containing all points in s
            int l = m, r = -1, u = n, d = -1;
            for (const auto& [row, col] : s) {
                l = min(l, col);
                r = max(r, col);
                u = min(u, row);
                d = max(d, row);
            }
            int ans = (r-l+1)*(d-u+1);
            if (k == 1) {
                return ans;
            }
            // vertical divide [l, i], [i+1, r]
            for (int i = l; i < r; ++i) {
                set<pair<int, int>> left, right;
                for (const auto& coord : s) {
                    if (coord.second <= i) left.insert(coord);
                    else right.insert(coord);
                }
                ans = min(ans, min(f(left, 1) + f(right, k-1), f(left, k-1) + f(right, 1)));
            }
            // horizontal divide [u, i], [i+1, d]
            for (int i = u; i < d; ++i) {
                set<pair<int, int>> up, down;
                for (const auto& coord : s) {
                    if (coord.first <= i) up.insert(coord);
                    else down.insert(coord);
                }
                ans = min(ans, min(f(up, 1) + f(down, k-1), f(up, k-1) + f(down, 1)));
            }
            return ans;
        };
        return f(s, 3);
    }
};
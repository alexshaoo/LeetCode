class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = n*m+1;
        int l = m, r = -1, u = n, d = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    l = min(l, j);
                    r = max(r, j);
                    u = min(u, i);
                    d = max(d, i);
                }
            }
        }
        auto solve = [&](int l, int r, int u, int d) -> int {
            int ll = r+1, rr = l-1, uu = d+1, dd = u-1;
            for (int row = u; row <= d; ++row) {
                for (int col = l; col <= r; ++col) {
                    if (grid[row][col]) {
                        ll = min(ll, col);
                        rr = max(rr, col);
                        uu = min(uu, row);
                        dd = max(dd, row);
                    }
                }
            }
            return (rr-ll+1)*(dd-uu+1);
        };
        vector<vector<int>> ps(n+1, vector<int>(m+1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                ps[i][j] = (grid[i-1][j-1]) + ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
            }
        }
        auto has = [&](int l, int r, int u, int d) -> bool {
            return ps[d+1][r+1] - ps[u][r+1] - ps[d+1][l] + ps[u][l] > 0;
        };
        // 3 vertical beams
        // [l, a), [a, b), [b, r]
        if (r-l >= 2) {
            for (int a = l+1; a <= r-1; ++a) {
                for (int b = a+1; b <= r; ++b) {
                    if (has(l, a-1, 0, n-1) && has(a, b-1, 0, n-1) && has(b, r, 0, n-1))
                        ans = min(ans, solve(l, a-1, 0, n-1) + solve(a, b-1, 0, n-1) + solve(b, r, 0, n-1));
                }
            }
        }
        // 3 horizontal beams
        // [u, a), [a, b), [b, d]
        if (d-u >= 2) {
            for (int a = u+1; a <= d-1; ++a) {
                for (int b = a+1; b <= d; ++b) {
                    if (has(0, m-1, u, a-1) && has(0, m-1, a, b-1) && has(0, m-1, b, d))
                        ans = min(ans, solve(0, m-1, u, a-1) + solve(0, m-1, a, b-1) + solve(0, m-1, b, d));
                }
            }
        }
        // choose dot, take full left, right, up, down, splitting other dir into two
        // dot includes above and to the left
        // for dot = (x, y), we split into 4 quadrants, <= x && <= y, > x && <= y, <= x && > y, > x && > y
        // then combine pairs of adjacent rectangles
        for (int i = u; i < d; ++i) {
            for (int j = l; j < r; ++j) {
                // (l, j, u, i), (j+1, r, u, i), (l, j, i+1, d), (j+1, r, i+1, d)
                // combine left
                if (has(l, j, u, d) && has(j+1, r, u, i) && has(j+1, r, i+1, d))
                    ans = min(ans, solve(l, j, u, d) + solve(j+1, r, u, i) + solve(j+1, r, i+1, d));
                // combine top
                if (has(l, r, u, i) && has(l, j, i+1, d) && has(j+1, r, i+1, d))
                    ans = min(ans, solve(l, r, u, i) + solve(l, j, i+1, d) + solve(j+1, r, i+1, d));
                // combine right
                if (has(j+1, r, u, d) && has(l, j, u, i) && has(l, j, i+1, d))
                    ans = min(ans, solve(j+1, r, u, d) + solve(l, j, u, i) + solve(l, j, i+1, d));
                // combine bottom
                if (has(l, r, i+1, d) && has(l, j, u, i) && has(j+1, r, u, i))
                    ans = min(ans, solve(l, r, i+1, d) + solve(l, j, u, i) + solve(j+1, r, u, i));
            }
        }
        return ans;
    }
};
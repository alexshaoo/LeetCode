class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // sum of squares = n * (n+1) * (2n+1) / 6
        // 1^2 + 2^2 + ... + n^2 = S
        // 1^2 + 2^2 + ... + (n-1)^2 = S
        // (k + 1)^3 - k^3 = 3k^2 + 3k + 1
        // sum of ((k + 1)^3 - k^3) = sum of (3k^2 + 3k + 1) 
        // (n + 1)^3 - 1 = 3 sum(k^2) + 3 sum(k) + n
        // 3 sum(k^2) = (n + 1)^3 - 3 sum(k) - n - 1 = n^3 + 3n^2 + 3n - 3(n(n+1))/2 - n
        // = n^3 + 3n^2 + 2n - (3/2)(n^2 + n) = (2n^3 + 6n^2 + 4n - 3n^2 - 3n) / 2 = (2n^3 + 3n^2 + n) / 2
        // sum(k^2) = n(n+1)(2n+1)/6
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> ps(n+1, vector<int>(m+1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ps[i+1][j+1] = ps[i][j+1] + ps[i+1][j] - ps[i][j] + (matrix[i][j] == 1);
            }
        }
        int ans = 0;
        for (int sz = 1; sz <= min(n, m); ++sz) {
            for (int i = 0; i < n-sz+1; ++i) {
                for (int j = 0; j < m-sz+1; ++j) {
                    int sm = ps[i+sz][j+sz] - ps[i][j+sz] - ps[i+sz][j] + ps[i][j];
                    if (sm == sz * sz) {
                        // cout << "updated" << ' ';
                        ++ans;
                    }
                    // cout << sz << ' ' << i << ' ' << j << '\n';
                }
            }
        }
        return ans;
    }
};
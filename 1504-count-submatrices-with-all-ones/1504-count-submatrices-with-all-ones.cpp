class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> rowAccum(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (j == 0) rowAccum[i][j] = (mat[i][j] == 1);
                else rowAccum[i][j] = (mat[i][j] == 0 ? 0 : rowAccum[i][j-1] + 1);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int minWidth = rowAccum[i][j];
                int row = i;
                int cnt = 0;
                while (row >= 0 && minWidth > 0) {
                    minWidth = min(minWidth, rowAccum[row][j]);
                    --row;
                    cnt += minWidth;
                }
                ans += cnt;
            }
        }
        return ans;
    }
};
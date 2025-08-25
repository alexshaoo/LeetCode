class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> ans;
        for (int i = 0; i < n+m-1; ++i) {
            if (i%2 == 0) { // go up
                int row = min(n-1, i);
                while (i-row < m && row >= 0) {
                    ans.push_back(mat[row][i-row]);
                    --row;
                }
            } else {
                int col = min(m-1, i);
                while (i-col < n && col >= 0) {
                    ans.push_back(mat[i-col][col]);
                    --col;
                }
            }
        }
        return ans;
    }
};
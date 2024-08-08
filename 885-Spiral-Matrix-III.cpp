class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans = {{rStart, cStart}};
        int dir[5] = {0, 1, 0, -1, 0};
        int i = 0, n = 0;
        while (ans.size() < rows*cols) {
            for (int j = 0; j < n/2-1; ++j) {
                rStart += dir[i];
                cStart += dir[i+1];
                if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) ans.push_back({rStart, cStart});
            }
            ++n;
            i = (i + 1) % 4;
        }
        return ans;
    }
};
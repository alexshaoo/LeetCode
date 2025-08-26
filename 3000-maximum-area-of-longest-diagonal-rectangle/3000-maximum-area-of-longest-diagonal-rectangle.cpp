class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int maxArea = 0, maxDiag = 0;
        for (auto dimension : dimensions) {
            int x = dimension[0], y = dimension[1];
            int diag = x*x + y*y;
            if (diag == maxDiag && x*y > maxArea) {
                maxArea = x*y;
            }
            if (diag > maxDiag) {
                maxDiag = diag;
                maxArea = x*y;
            }
        }
        return maxArea;
    }
};
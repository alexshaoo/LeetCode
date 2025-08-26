class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int maxArea = 0, maxDiag = 0;
        for (const auto& dimension : dimensions) {
            int x = dimension[0], y = dimension[1];
            int diag = x*x + y*y;
            int area = x*y;
            if (diag == maxDiag) {
                maxArea = max(maxArea, area);
            } else if (diag > maxDiag) {
                maxDiag = diag;
                maxArea = area;
            }
        }
        return maxArea;
    }
};
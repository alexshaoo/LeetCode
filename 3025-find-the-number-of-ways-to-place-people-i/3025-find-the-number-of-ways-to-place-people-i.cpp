class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            vector<vector<int>> tl;
            for (int j = 0; j < n; ++j) {
                if (j != i && points[j][0] <= points[i][0] && points[j][1] >= points[i][1]) tl.push_back(points[j]);
            }
            for (int j = 0; j < tl.size(); ++j) {
                bool found = false;
                for (int k = 0; k < tl.size(); ++k) {
                    if (k != j && tl[k][0] >= tl[j][0] && tl[k][1] <= tl[j][1]) {
                        found = true;
                        break;
                    }
                }
                if (!found) ++cnt;
            }
        }
        return cnt;
    }
};
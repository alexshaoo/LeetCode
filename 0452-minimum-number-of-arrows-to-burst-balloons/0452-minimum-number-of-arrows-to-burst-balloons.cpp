class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });
        
        int n = points.size();
        int ans = 1;
        int r = points[0][1];
        
        for (int i = 1; i < n; ++i) {
            if (points[i][0] > r) {
                ++ans;
                r = points[i][1];
            } else {
                r = min(r, points[i][1]);
            }
        }
        return ans;
    }
};
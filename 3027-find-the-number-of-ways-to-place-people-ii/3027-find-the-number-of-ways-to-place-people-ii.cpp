class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });
        for (int i = 0; i < n; ++i) {
            int low = INT_MIN;
            for (int j = i+1; j < n; ++j) {
                if (points[i][1] < points[j][1]) continue;
                if (points[j][1] <= low) continue;
                low = max(low, points[j][1]);
                ++ans;
            }
        }
        return ans;
    }
};
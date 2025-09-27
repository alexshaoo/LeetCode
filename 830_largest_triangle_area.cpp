class Solution {
public:
  int det(vector<int>& a, vector<int>& b) {
    return b[1] * a[0] - b[0] * a[1];
  }
  double largestTriangleArea(vector<vector<int>>& points) {
    int n = points.size();
    double mx = 0.0;
    for (int i = 0; i < n-2; ++i) {
      for (int j = i+1; j < n-1; ++j) {
        for (int k = j+1; k < n; ++k) {
          mx = max(mx, 0.5 * abs(det(points[i], points[j]) + det(points[j], points[k]) + det(points[k], points[i])));
        }
      }
    }
    return mx;
  }
};
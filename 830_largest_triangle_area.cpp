class Solution {
public:
  double largestTriangleArea(vector<vector<int>>& points) {
    int n = points.size();
    double mx = 0.0;
    for (const auto& a : points) {
      for (const auto& b : points) {
        for (const auto& c : points) {
          double val = 0.5*((b[0]-a[0])*(c[1]-a[1]) - (b[1]-a[1])*(c[0]-a[0]));
          mx = max(mx, max(val, -val)); 
        }
      }
    }
    return mx;
  }
};
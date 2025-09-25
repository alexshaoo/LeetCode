class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> dp(n+2, INT_MAX);
    dp[1] = triangle[0][0];
    for (int i = 1; i < n; ++i) {
      for (int j = i+1; j >= 1; --j) {
        dp[j] = min(dp[j-1], dp[j]) + triangle[i][j-1];
      }
    }
    return *min_element(dp.begin(), dp.end());
  }
};
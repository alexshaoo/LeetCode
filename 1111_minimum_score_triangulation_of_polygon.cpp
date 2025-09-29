class Solution {
public:
  int dp[50][50];
  int f(vector<int>& values, int i, int j) {
    if (dp[i][j] != 0) return dp[i][j];
    int ans = 0;
    for (int k = i+1; k < j; ++k) {
      ans = min(ans == 0 ? INT_MAX : ans, values[i]*values[j]*values[k] + f(values, i, k) + f(values, k, j));
    }
    dp[i][j] = ans;
    return ans;
  }
  int minScoreTriangulation(vector<int>& values) {
    memset(dp, 0, sizeof(dp));
    return f(values, 0, values.size()-1);
  }
};
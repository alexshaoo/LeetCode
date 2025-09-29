class Solution {
public:
  int dp[50][50];
  int f(vector<int>& values, int i, int j) {
    // cout << i << ' ' << j << '\n';
    if (dp[i][j] != 0) return dp[i][j];
    int ans = 0;
    for (int k = i+1; k < j; ++k) {
      int w = values[i] * values[j] * values[k];
      ans = min(ans == 0 ? INT_MAX : ans, w + f(values, i, k) + f(values, k, j));
    }
    dp[i][j] = ans;
    return ans;
  }
  int minScoreTriangulation(vector<int>& values) {
    memset(dp, 0, sizeof(dp));
    int n = values.size();
    for (int i = 0; i < n ; ++i) {
      int j = (i+1)%n;
      int k = (i+2)%n;
      dp[i][k] = values[i]*values[j]*values[k];
    }
    int ans = f(values, 0, n-1);
    // for (int i = 0; i < n; ++i) {
    //   for (int j = 0; j < n; ++j) {
    //     cout << dp[i][j] << ' ';
    //   }
    //   cout << '\n';
    // }
    return ans;
  }
};
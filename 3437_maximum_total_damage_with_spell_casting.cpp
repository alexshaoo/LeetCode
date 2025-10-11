class Solution {
public:
  long long maximumTotalDamage(vector<int>& power) {
    int n = power.size();
    sort(power.begin(), power.end());
    vector<long long> dp(n+1, 0);
    long long mx = 0;
    for (int i = 0, j = 0; i < n; ++i) {
      if (i == 0 || power[i] == power[i-1]) {
        dp[i+1] = dp[i] + power[i];
      } else {
        while (power[j] < power[i]-2) {
          mx = max(mx, dp[j+1]);
          ++j;
        }
        dp[i+1] = power[i] + mx;
      }
    }
    return *max_element(dp.begin(), dp.end());
  }
};
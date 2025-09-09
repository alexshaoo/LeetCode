class Solution {
public:
  static constexpr int MOD = 1e9+7;
  int peopleAwareOfSecret(int n, int delay, int forget) {
    vector<long long> dp(n+1, 0); // dp[i] is the number of people who found out on day
    dp[1] = 1LL;
    long long share = 0;
    for (int d = 2; d <= n; ++d) {
      if (d-delay > 0) {
        share += dp[d-delay];
      }
      if (d-forget > 0) {
        share -= dp[d-forget];
      }
      share = (share + MOD) % MOD;
      dp[d] = share;
    }
    long long cnt = 0;
    for (int d = n-forget+1; d <= n; ++d) {
      cnt = (cnt + dp[d]) % MOD;
    }
    return (int)cnt;
  }
};
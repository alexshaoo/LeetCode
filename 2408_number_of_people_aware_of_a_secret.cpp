class Solution {
public:
  static constexpr int MOD = 1e9+7;
  int peopleAwareOfSecret(int n, int delay, int forget) {
    vector<long long> dp(n+1, 0);
    dp[1] = 1LL;
    for (int i = 1; i <= n; ++i) {
      for (int j = i+delay; j < min(n+1, i+forget); ++j) {
        dp[j] = (dp[j] + dp[i]) % MOD;
      }
    }
    long long cnt = 0;
    for (int day = n; day > max(-1, n-forget); --day) {
      cnt = (cnt + dp[day]) % MOD;
    }
    return (int)cnt;
  }
};
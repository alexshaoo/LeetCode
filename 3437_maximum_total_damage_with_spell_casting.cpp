class Solution {
public:
  long long maximumTotalDamage(vector<int>& power) {
    set<int> s;
    for (int x : power) s.insert(x);
    int n = s.size();
    vector<int> v(s.begin(), s.end());
    unordered_map<int, int> mp;
    for (int x : power) mp[x]++;
    vector<vector<long long>> dp(n, vector<long long>(2, 0));
    for (int i = 0; i < n; ++i) {
      // did not cast current
      if (i > 0) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
      }
      // cast current
      dp[i][1] = mp[v[i]]*(long long)v[i];
      int idx = i;
      while (idx >= 0 && v[idx]+2 >= v[i]) --idx;
      if (idx >= 0) {
        dp[i][1] += max(dp[idx][0], dp[idx][1]);
      }
    }
    // for (int i = 0; i < n; ++i) {
    //   cout << dp[i][0] << ' ' << dp[i][1] << '\n';
    // }
    // cout << '\n';
    return max(dp[n-1][0], dp[n-1][1]);
  }
};
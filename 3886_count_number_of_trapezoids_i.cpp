class Solution {
public:
  int countTrapezoids(vector<vector<int>>& points) {
    const int MOD = 1e9+7;
    unordered_map<int, long long> groups;
    for (const auto& p : points) {
      groups[p[1]]++;
    }
    long long ans = 0, tot = 0;
    for (const auto& g : groups) {
      long long cnt = g.second;
      long long lines = cnt * (cnt-1) / 2;
      ans = (ans + tot * lines) % MOD;
      tot = (tot + lines) % MOD;
    }
    return (int)ans;
  }
};
class Solution {
public:
  long long maximumImportance(int n, vector<vector<int>>& roads) {
    vector<long long> deg(n);
    for (const auto& road : roads) {
      int u = road[0], v = road[1];
      deg[u]++;
      deg[v]++;
    }
    sort(deg.begin(), deg.end(), [](const long long& a, const long long& b) {
      return a > b;
    });
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      if (deg[i] == 0) break;
      ans += (n-i) * deg[i];
    }
    return ans;
  }
};
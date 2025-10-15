class Solution {
public:
  long long maximumImportance(int n, vector<vector<int>>& roads) {
    vector<long long> deg(n);
    for (const auto& road : roads) {
      int u = road[0], v = road[1];
      deg[u]++;
      deg[v]++;
    }
    vector<long long> freq(n);
    for (const auto& d : deg) freq[d]++;
    long long ans = 0;
    long long val = 1;
    for (long long i = 0; i < n; ++i) {
      for (long long f = freq[i]; f > 0; --f) {
        ans += val * i;
        ++val;
      }
    }
    return ans;
  }
};
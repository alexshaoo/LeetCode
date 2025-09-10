class Solution {
public:
  int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
    int m = languages.size();
    vector<vector<bool>> adj(m+1, vector<bool>(n+1, false));
    for (int i = 0; i < m; ++i) {
      for (const auto& l : languages[i])
        adj[i+1][l] = true;
    }
    vector<bool> learn(m+1, false);
    for (const auto& f : friendships) {
      int u = f[0], v = f[1];
      bool know = false;
      for (int i = 1; i <= n; ++i) {
        if (adj[u][i] && adj[v][i]) {
          know = true;
          break;
        }
      }
      if (!know) {
        learn[u] = true;
        learn[v] = true;
      }
    }
    int ans = 505;
    for (int l = 1; l <= n; ++l) {
      int cnt = 0;
      for (int u = 1; u <= m; ++u) {
        if (learn[u] && !adj[u][l]) ++cnt;
      }
      ans = min(ans, cnt);
    }
    return ans;
  }
};
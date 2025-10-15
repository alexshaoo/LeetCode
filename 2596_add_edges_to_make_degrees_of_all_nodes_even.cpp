class Solution {
public:
  bool isPossible(int n, vector<vector<int>>& edges) {
    unordered_map<int, unordered_map<int, bool>> adj;
    vector<int> oddDeg;
    unordered_map<int, int> deg;
    for (const auto& edge : edges) {
      int u = edge[0], v = edge[1];
      adj[u][v] = true;
      adj[v][u] = true;
      deg[u]++;
      deg[v]++;
    }
    for (const auto& [k, v] : deg) {
      if (v%2==1) oddDeg.push_back(k);
    }
    int numOdd = oddDeg.size();
    cout << numOdd << '\n';
    if (numOdd % 2 == 1) return false;
    if (numOdd <= 0) return true;
    if (numOdd == 2) {
      int u = oddDeg[0], v = oddDeg[1];
      if (!adj[u][v]) return true;
      for (int w = 1; w <= n; ++w) {
        if (w != u && w != v && !adj[u][w] && !adj[v][w]) return true;
      }
      return false;
    } else if (numOdd == 4) {
      int u = oddDeg[0], v = oddDeg[1], w = oddDeg[2], x = oddDeg[3];
      return !adj[u][v] && !adj[w][x] || !adj[u][w] && !adj[v][x] || !adj[u][x] && !adj[v][w];
    }
    return false;
  }
};
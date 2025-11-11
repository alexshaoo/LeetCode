class Solution {
public:
  double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
    unordered_map<int, vector<pair<int, double>>> adj; // u -> {v, prob}
    for (int i = 0; i < edges.size(); ++i) {
      adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
      adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
    }
    auto cmp = [](const pair<int, double>& a, const pair<int, double>& b) {
      return a.second < b.second;
    };
    vector<bool> vis(n);
    priority_queue<pair<int, double>, vector<pair<int, double>>, decltype(cmp)> pq; // node we land on, prob
    pq.push({start_node, 1.0});
    while (!pq.empty()) {
      auto [u, prob] = pq.top(); pq.pop();
      if (vis[u]) continue;
      vis[u] = true;
      if (u == end_node) return prob;
      for (const auto& [v, newProb] : adj[u]) {
        pq.push({v, prob*newProb});
      }
    }
    return 0.0;
  }
};
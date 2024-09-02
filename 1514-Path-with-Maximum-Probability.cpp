class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0]; int v = edges[i][1];
            auto s = succProb[i];
            adj[u].push_back({ v, s });
            adj[v].push_back({ u, s });
        }
        vector<double> prob(n, 0.0); 
        prob[start_node] = 1.0;
        priority_queue<pair<int, double>> pq; 
        pq.push({ start_node, 1.0 });
        while (!pq.empty()) {
            auto [u, p] = pq.top(); 
            pq.pop();
            if (p < prob[u]) continue;
            for (auto& [v, np] : adj[u]) {
                if (p * np > prob[v]) {
                    prob[v] = p * np;
                    pq.push({v, prob[v]});
                }
            }
        }
        return prob[end_node];
    }
};
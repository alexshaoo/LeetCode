class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outdeg(n);
        unordered_set<int> safe;
        unordered_map<int, vector<int>> back;
        vector<int> ans;
        for (int u = 0; u < n; ++u) {
            auto adj = graph[u];
            outdeg[u] = adj.size();
            if (outdeg[u] == 0) safe.insert(u);
            for (int v : adj) {
                back[v].push_back(u);
            }
        }
        while (!safe.empty()) {
            int top = *(safe.begin());
            safe.erase(safe.begin());
            ans.push_back(top);
            for (int u : back[top]) {
                outdeg[u]--;
                if (outdeg[u] == 0) safe.insert(u);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
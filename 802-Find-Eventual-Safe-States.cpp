class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> outdeg(n), ans;
        queue<int> safe;
        vector<vector<int>> back(n);
        for (int u = 0; u < n; ++u) {
            outdeg[u] = graph[u].size();
            if (outdeg[u] == 0) safe.push(u);
            for (int v : graph[u]) {
                back[v].push_back(u);
            }
        }
        while (!safe.empty()) {
            int top = safe.front();
            safe.pop();
            ans.push_back(top);
            for (int u : back[top]) {
                outdeg[u]--;
                if (outdeg[u] == 0) safe.push(u);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
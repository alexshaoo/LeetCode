class Solution {
public:
    void dfs(int u, stack<int>& s, vector<vector<int>>& edges, vector<bool>& vis) {
        vis[u] = true;
        for (const auto v : edges[u]) if (!vis[v]) dfs(v, s, edges, vis);
        s.push(u);
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        stack<int> s;
        vector<unordered_set<int>> ans(n);
        vector<bool> vis(n);
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) adj[edge[0]].push_back(edge[1]);
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) dfs(i, s, adj, vis);
        }
        while (!s.empty()) {
            int u = s.top();
            for (int v : adj[u]) {
                ans[v].insert(u);
                for (const auto& el : ans[u]) ans[v].insert(el);
                // ans[v].insert(ans[v].end(), ans[u].begin(), ans[u].end());
            }
            s.pop();
        }
        vector<vector<int>> res(n);
        for (int i = 0; i < n; ++i) {
            vector<int> tmp(ans[i].begin(), ans[i].end());
            sort(tmp.begin(), tmp.end());
            res[i].insert(res[i].end(), tmp.begin(), tmp.end());
        }
        return res;
    }
};
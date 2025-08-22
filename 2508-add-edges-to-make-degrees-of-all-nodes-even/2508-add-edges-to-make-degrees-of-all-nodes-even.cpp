class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> degs(n+1, 0);
        for (auto edge : edges) {
            int u = edge[0], v = edge[1];
            degs[u]++;
            degs[v]++;
        }
        vector<int> oddDegs;
        for (int i = 1; i <= n; ++i) {
            if (degs[i] % 2 == 1) oddDegs.push_back(i);
        }
        if (oddDegs.size() > 4) return false;
        vector<unordered_set<int>> adj(n+1);
        for (auto edge : edges) {
            int u = edge[0], v = edge[1];
            auto it = find(oddDegs.begin(), oddDegs.end(), u);
            if (it != oddDegs.end()) {
                adj[u].insert(v);
            }
            it = find(oddDegs.begin(), oddDegs.end(), v);
            if (it != oddDegs.end()) {
                adj[v].insert(u);
            }
        }
        if (oddDegs.size() == 0) return true;
        if (oddDegs.size() == 2) {
            int u = oddDegs[0], v = oddDegs[1];
            for (int i = 1; i <= n; ++i) {
                if ((adj[u].count(i) == 0) && (adj[v].count(i) == 0)) return true;
            }
            return false;
        }
        if (oddDegs.size() == 4) {
            sort(oddDegs.begin(), oddDegs.end());
            do {
                if ((adj[oddDegs[0]].count(oddDegs[1]) == 0) && (adj[oddDegs[2]].count(oddDegs[3]) == 0)) return true;
            } while (next_permutation(oddDegs.begin(), oddDegs.end()));
            return false;
        }
        return false;
    }
};
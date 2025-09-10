class Solution {
public:
  bool f(unordered_set<int> s1, unordered_set<int> s2) {
    if (s1.size() > s2.size()) swap(s1, s2);
    for (const auto& x : s1) {
      if (s2.contains(x)) return true;
    }
    return false;
  }
  int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
    int m = languages.size();
    vector<unordered_set<int>> ul(m+1);
    for (int i = 0; i < m; ++i) {
      ul[i+1] = unordered_set(languages[i].begin(), languages[i].end());
    }
    vector<vector<int>> cant; // friends that can't communicate
    for (auto fs : friendships) {
      int u = fs[0], v = fs[1];
      if (!f(ul[u], ul[v])) {
        cant.push_back({u, v});
      }
    }
    int ans = 505;
    for (int l = 1; l <= n; ++l) {
      int cnt = 0;
      for (auto fs : cant) {
        int u = fs[0], v = fs[1];
        if (ul[u].contains(l) && ul[v].contains(l)) continue;
        if (!ul[u].contains(l)) {
          ++cnt;
          ul[u].insert(l);
        }
        if (!ul[v].contains(l)) {
          ++cnt;
          ul[v].insert(l);
        }
      }
      ans = min(ans, cnt);
    }
    return ans;
  }
};
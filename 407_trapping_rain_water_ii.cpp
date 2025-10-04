class Solution {
public:
  int trapRainWater(vector<vector<int>>& heightMap) {
    int n = heightMap.size(), m = heightMap[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    // auto cmp = [&](const array<int, 3>& a, const array<int, 3>& b) {
    //   return a[2] > b[2];
    // };
    struct cmp {
      bool operator()(const array<int, 3>& a, const array<int, 3>& b) const {
        return a[2] > b[2];
      }
    };
    priority_queue<array<int, 3>, vector<array<int, 3>>, cmp> mh;
    auto f = [&](int r, int c) {
      if (!vis[r][c]) {
        vis[r][c] = true;
        mh.push({r, c, heightMap[r][c]});
      }
    };
    for (int i = 0; i < n; ++i) {
      f(i, 0);
      f(i, m-1);
    }
    for (int i = 0; i < m; ++i) {
      f(0, i);
      f(n-1, i);
    }
    vector<vector<int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    vector<int> d = {-1, 0, 1, 0, -1};
    int v = 0;
    while (!mh.empty()) {
      auto [r, c, h] = mh.top(); mh.pop();
      for (int i = 0; i < 4; ++i) {
        int nr = r+d[i], nc = c+d[i+1];
        if (!(nr >= 0 && nr < n && nc >= 0 && nc < m)) continue;
        if (vis[nr][nc]) continue;
        vis[nr][nc] = true;
        v += max(0, h - heightMap[nr][nc]);
        mh.push({nr, nc, max(h, heightMap[nr][nc])});
      }
    }
    return v;
  }
};
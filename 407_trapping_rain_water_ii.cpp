class Solution {
public:
  int trapRainWater(vector<vector<int>>& heightMap) {
    int n = heightMap.size();
    int m = heightMap[0].size();
    int v = 0;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    auto cmp = [&](const array<int, 3>& a, const array<int, 3>& b) {
      return a[0] > b[0];
    };
    priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(cmp)> mh(cmp);
    for (int i = 0; i < n; ++i) {
      mh.push({heightMap[i][0], i, 0});
      mh.push({heightMap[i][m-1], i, m-1});
      vis[i][0] = true;
      vis[i][m-1] = true;
    }
    for (int i = 0; i < m; ++i) {
      mh.push({heightMap[0][i], 0, i});
      mh.push({heightMap[n-1][i], n-1, i});
      vis[0][i] = true;
      vis[n-1][i] = true;
    }
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (!mh.empty()) {
      auto [h, r, c] = mh.top(); mh.pop();
      for (auto dir : dirs) {
        int nr = r+dir[0], nc = c+dir[1];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]) {
          vis[nr][nc] = true;
          if (heightMap[nr][nc] < h) v += (h-heightMap[nr][nc]);
          mh.push({max(h, heightMap[nr][nc]), nr, nc});
        }
      }
    }
    return v;
  }
};
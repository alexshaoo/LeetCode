class Solution {
public:
  int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    using cell = array<int, 3>; // r, c, h
    auto cmp = [&](const cell& a, const cell& b) {
      return a[2] > b[2];
    };
    priority_queue<cell, vector<cell>, decltype(cmp)> pq(cmp);
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    vector<int> dirs = {0, -1, 0, 1, 0};
    pq.push({0, 0, grid[0][0]});
    vis[0][0] = true;
    int gh = 0;
    while (!pq.empty()) {
      auto [r, c, h] = pq.top(); pq.pop();
      gh = max(gh, h);
      if (r == n-1 && c == n-1) return gh;
      for (int i = 0; i < 4; ++i) {
        int nr = r+dirs[i], nc = c+dirs[i+1];
        if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc]) {
          pq.push({nr, nc, grid[nr][nc]});
          vis[nr][nc] = true;
        }
      }
    }
    return -1;
  }
};
class Solution {
public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    int r = (int)grid.size();
    int c = (int)grid[0].size();
    int d[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

    queue<vector<int>> q;
    int dp[r][c];
    memset(dp, -1, sizeof(dp));
    
    q.push({0, 0, 0, k});
    while (!q.empty()) {
      vector<int> cur = q.front();
      q.pop();
      int x = cur[0], y = cur[1], val = cur[2], kill = cur[3];
      if (x < 0 || x >= r || y < 0 || y >= c || kill <= dp[x][y]) continue;
      if (x == r-1 && y == c-1) return val;
      dp[x][y] = kill - grid[x][y];
      for (int i = 0; i < 4; i++) q.push({x+d[i][0], y + d[i][1], val+1, dp[x][y]});
    }

    return -1;
  }
};
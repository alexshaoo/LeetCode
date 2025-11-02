class Solution {
public:
  int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
    vector<int> dirs = {0, -1, 0, 1, 0};
    vector<int> seen(m*n); // can be seen by guard is 1, guard/wall is 2
    for (const auto& wall : walls) {
      seen[wall[0]*n+wall[1]] = 2;
    }
    for (const auto& guard : guards) {
      seen[guard[0]*n+guard[1]] = 2;
    }
    int occ = walls.size() + guards.size();
    for (const auto& guard : guards) {
      int r = guard[0], c = guard[1];
      for (int i = 0; i < 4; ++i) {
        int nr = r, nc = c;
        while (true) {
          nr += dirs[i];
          nc += dirs[i+1];
          if (min(nr, nc) < 0 || nr >= m || nc >= n || seen[nr*n+nc] == 2) break;
          if (seen[nr*n+nc] != 1) {
            ++occ;
            seen[nr*n+nc] = 1;
          }
        }
      }
    }
    return m*n-occ;
  }
};
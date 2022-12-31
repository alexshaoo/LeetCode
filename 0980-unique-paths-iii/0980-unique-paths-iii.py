class Solution:
  def uniquePathsIII(self, grid: List[List[int]]) -> int:
    m, n, cnt, flat = len(grid), len(grid[0]), 0, sum(grid, [])
    def dfs(i, j, left):
      nonlocal cnt
      grid[i][j] = -1
      for x, y in ((i-1,j),(i+1,j),(i,j-1),(i,j+1)):
        if 0 <= x < m and 0 <= y < n:
          if not grid[x][y]: dfs(x, y, left-1)
          if grid[x][y] == 2: cnt += not left
      grid[i][j] = 0
    dfs(*divmod(flat.index(1), n), flat.count(0))
    return cnt
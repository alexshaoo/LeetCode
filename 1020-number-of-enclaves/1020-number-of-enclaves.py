class Solution:
  def numEnclaves(self, grid: List[List[int]]) -> int:
    n,m = len(grid),len(grid[0])
    def dfs(i,j):
      if 0 <= i < n and 0 <= j < m and grid[i][j] == 1:
        grid[i][j] = 0
        for x,y in (i+1,j), (i-1,j), (i,j+1), (i,j-1):
          dfs(x,y)
    for i in range(n):
      dfs(i,0)
      dfs(i,m-1)
    for i in range(m):
      dfs(0,i)
      dfs(n-1,i)
    return sum(sum(row) for row in grid)
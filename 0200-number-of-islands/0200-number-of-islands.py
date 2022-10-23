class Solution:
  def numIslands(self, grid: List[List[str]]) -> int:
    r = len(grid)
    c = len(grid[0])
    def sink(i, j):
      if 0 <= i < r and 0 <= j < c and grid[i][j] == '1':
        grid[i][j] = '0'
        sink(i+1, j)
        sink(i-1, j)
        sink(i, j+1)
        sink(i, j-1)
        return 1
      return 0
    return sum(sink(i, j) for i in range(r) for j in range(c))
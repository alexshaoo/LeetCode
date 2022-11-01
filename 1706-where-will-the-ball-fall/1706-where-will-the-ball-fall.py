class Solution:
  def findBall(self, grid: List[List[int]]) -> List[int]:
    r = len(grid)
    c = len(grid[0])
    res = []
    for cc in range(c):
      row = 0
      col = cc
      while row < r:
        slope = grid[row][col]
        # dead
        if slope == 1:
          if col == c-1 or grid[row][col+1] == -1:
            res.append(-1)
            break
          else:
            row += 1
            col += 1
        if slope == -1:
          if col == 0 or grid[row][col-1] == 1:
            res.append(-1)
            break
          else:
            row += 1
            col -= 1
      if row == r:
        res.append(col)
    return res
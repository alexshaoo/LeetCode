class Solution:
  def diagonalSum(self, mat: List[List[int]]) -> int:
    i = 0
    n = len(mat)
    s = 0
    while i < n:
      s += mat[i][i]
      mat[i][i] = 0
      s += mat[i][n-i-1]
      i += 1
    return s
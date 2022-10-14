class Solution:
  def totalNQueens(self, n: int) -> int:
    def backtrack(queens=[], d1=[], d2=[]):
      l = len(queens)
      return (l == n) + sum([backtrack(queens+[j], d1+[j-l], d2+[j+l]) for j in range(n) if j not in queens and j-l not in d1 and j+l not in d2])
    
    return backtrack()
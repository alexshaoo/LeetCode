class Solution:
  def solveNQueens(self, n: int) -> List[List[str]]:
    col = set()
    pos = set()
    neg = set()
    
    ans = []
    board = [['.']*n for _ in range(n)]
    
    def backtrack(r):
      if r == n:
        ans.append(["".join(row) for row in board])
        return
      
      for c in range(n):
        if c not in col and r+c not in pos and r-c not in neg:
          
          board[r][c] = "Q"
          col.add(c)
          pos.add(r+c)
          neg.add(r-c)
          
          backtrack(r+1)
          
          board[r][c] = '.'
          col.remove(c)
          pos.remove(r+c)
          neg.remove(r-c)
          
    backtrack(0)
    
    return ans
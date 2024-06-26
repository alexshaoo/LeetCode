class Solution:
  def isValidSudoku(self, board: List[List[str]]) -> bool:
    big = set()
    for i in range(0,9):
      for j in range(0,9):
        if board[i][j]!='.':
          cur = board[i][j]
          if (i,cur) in big or (cur,j) in big or (i//3,j//3,cur) in big:
            return False
          big.add((i,cur))
          big.add((cur,j))
          big.add((i//3,j//3,cur))
    return True
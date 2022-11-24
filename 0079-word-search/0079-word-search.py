class Solution:
  def exist(self, board: List[List[str]], word: str) -> bool:
    l, rows, cols = len(word), len(board), len(board[0])
    def dfs(x, y, d):
      if d == l: 
        return True
      else:
        if 0 <= x < cols and 0 <= y < rows:
          let = board[y][x]
          if let == word[d]:
            board[y][x] = ""
            for dx, dy in ((0,1),(0,-1),(1,0),(-1,0)):
              if dfs(x+dx, y+dy, d+1): 
                return True
            board[y][x] = let
          
    counter = Counter(word)
    coords = []
    for r in range(rows):
      for c in range(cols):
        let = board[r][c]
        counter[let] -= 1
        if let == word[0]: 
          coords.append((r, c))
    if max(counter.values()) > 0: 
      return False
    for r, c in coords:
      if dfs(c, r, 0): 
        return True
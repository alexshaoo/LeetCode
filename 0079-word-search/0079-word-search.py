class Solution:
  def exist(self, board: List[List[str]], word: str) -> bool:
    rows, cols = len(board), len(board[0])
    def bt(r, c, i):
      if i == len(word):return True
      if not (0 <= r < rows and 0 <= c < cols and board[r][c] == word[i]):return False
      board[r][c], ch = None, board[r][c]
      for (rr, cc) in ((r+1, c), (r-1, c), (r, c+1), (r, c-1)):
        if bt(rr, cc, i+1):return True
      board[r][c] = ch
    word_counter, board_counter = Counter(word), Counter(sum(board, []))
    for ch, cnt in word_counter.items():
      if board_counter[ch] < cnt:return False
    if word_counter[word[-1]] < word_counter[word[0]]:word = word[::-1]
    for r in range(rows):
      for c in range(cols):
        if bt(r, c, 0):return True
    return False
  
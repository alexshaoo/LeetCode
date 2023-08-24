class Solution:
  def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
    res, cur, n = [], [], 0
    for w in words:
      if n + len(w) + len(cur) > maxWidth:
        for i in range(maxWidth - n):
          cur[i%(len(cur)-1 or 1)] += ' '
        res.append(''.join(cur))
        cur, n = [], 0
      cur += [w]
      n += len(w)
    return res + [' '.join(cur).ljust(maxWidth)]
    
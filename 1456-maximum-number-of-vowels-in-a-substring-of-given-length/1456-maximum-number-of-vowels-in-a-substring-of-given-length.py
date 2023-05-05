class Solution:
  def maxVowels(self, s: str, k: int) -> int:
    n = len(s)
    lst = [1 if ss in "aeiou" else 0 for ss in s]
    c = sum(lst[:k])
    m = c
    l, r = 0, k
    while r < n:
      c = c + lst[r] - lst[l]
      l += 1
      r += 1
      m = max(m, c)
    return m
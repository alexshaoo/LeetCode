class Solution:
  def maximum69Number(self, n: int) -> int:
    c, u, m = -1, 0, n
    while m:
      if m % 10 == 6:
        c = u
      m //= 10
      u += 1
    if c == -1:
      return n
    return n + 3*10**c
    
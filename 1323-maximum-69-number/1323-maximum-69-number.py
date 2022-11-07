class Solution:
  def maximum69Number(self, num: int) -> int:
    c, u, m = -1, 0, num
    while m:
      if m % 10 == 6:
        c = u
      m //= 10
      u += 1
    if c == -1:
      return num
    return num + 3*10**c
    
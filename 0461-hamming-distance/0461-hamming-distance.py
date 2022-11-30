class Solution:
  def hammingDistance(self, x: int, y: int) -> int:
    c = 0
    for l in bin(x ^ y)[2:]:
      if l == '1':
        c += 1
    return c
      
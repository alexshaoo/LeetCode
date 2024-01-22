class Solution:
  def minEatingSpeed(self, piles: List[int], h: int) -> int:
    n = len(piles)
    l = 1
    r = max(piles)
    def f(k):
      s = 0
      for pile in piles:
        s += ceil(pile / k)
      return s <= h
    while l < r:
      m = l + (r-l)//2
      if f(m):
        r = m
      else:
        l = m+1
    return l
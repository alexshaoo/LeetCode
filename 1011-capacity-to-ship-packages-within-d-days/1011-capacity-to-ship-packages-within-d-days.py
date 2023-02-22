class Solution:
  def shipWithinDays(self, weights: List[int], days: int) -> int:
    def f(cap):
      s,c  = 0,0
      for i, weight in enumerate(weights):
        if s + weight > cap:
          c += 1
          s = 0
        s += weight
      return c+1
    l,r = max(weights),sum(weights)
    while l<r:
      m = (l+r)//2
      # print(l, r, m, f(m))
      if f(m) <= days:
        r = m
      else:
        l = m+1
    return l
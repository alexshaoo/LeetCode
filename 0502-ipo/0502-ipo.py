class Solution:
  def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
    pool, new = [], [(c, p) for c, p in zip(capital, profits)]
    heapq.heapify(new)
    for i in range(k):
      while new and new[0][0] <= w: heapq.heappush(pool, -heapq.heappop(new)[1])
      try: w -= heapq.heappop(pool)
      except: break
    return w
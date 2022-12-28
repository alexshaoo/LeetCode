class Solution:
  def minStoneSum(self, piles: List[int], k: int) -> int:
    h = []
    for pile in piles:
      heappush(h, -pile)
    for _ in range(k):
      heappush(h, heappop(h)//2)
    return -sum(h)
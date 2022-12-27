class Solution:
  def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
    rocks = sorted([c-r for c, r in zip(capacity, rocks)])
    n = len(rocks)
    i = 0
    # print(rocks)
    while i < n and additionalRocks >= rocks[i]:
      # print(additionalRocks, i)
      additionalRocks -= rocks[i]
      i += 1
    return i
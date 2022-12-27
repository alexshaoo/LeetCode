class Solution:
  def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
    rocks = sorted([c-r for c, r in zip(capacity, rocks)])
    n = len(rocks)
    i = 0
    # print(rocks)
    return bisect_right(list(accumulate(rocks)), additionalRocks)
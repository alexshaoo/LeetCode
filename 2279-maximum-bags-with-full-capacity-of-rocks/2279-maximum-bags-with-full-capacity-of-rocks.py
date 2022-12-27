class Solution:
  def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
    return bisect_right(list(accumulate(sorted(c - r for c, r in zip(capacity, rocks)))), additionalRocks)
class Solution:
  def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
    res = 0
    while (minutesToTest/minutesToDie + 1)**res < buckets:
      res += 1
    return res

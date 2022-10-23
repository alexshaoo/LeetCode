class Solution:
  def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
    d = {}
    for i, num in enumerate(nums):
      if num in d and abs(d[num] - i) <= k:
        return True
      d[num] = i
    return False
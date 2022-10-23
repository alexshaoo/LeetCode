class Solution:
  def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
    d = {}
    for i, num in enumerate(nums):
      if num not in d:
        d[num] = i
      else:
        if abs(d[num] - i) <= k:
          return 1
        d[num] = i
        
    return 0
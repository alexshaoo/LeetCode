class Solution:
  def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
    if len(set(nums)) == len(nums):
      return False
    for i,item in enumerate(nums):
      subs = nums[i:i+k+1]
      if len(set(subs))<len(subs):
        return True

    return False
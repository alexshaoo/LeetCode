class Solution:
  def canJump(self, nums: List[int]) -> bool:
    j = nums[0]
    for num in nums[:-1]:
      j = max(j-1, num)
      if j == 0:
        return False
    return True
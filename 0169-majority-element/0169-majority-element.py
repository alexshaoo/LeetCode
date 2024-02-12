class Solution:
  def majorityElement(self, nums: List[int]) -> int:
    ans = nums[0]
    c = 1
    for i in range(1, len(nums)):
      if ans == nums[i]:
        c += 1
      elif c == 0:
        ans = nums[i]
        c += 1
      else:
        c -= 1
    return ans
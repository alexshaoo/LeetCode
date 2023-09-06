class Solution:
  def minimumReplacement(self, nums: List[int]) -> int:
    res = 0
    n = len(nums)
    for i in range(n-2, -1, -1):
      if nums[i] <= nums[i+1]:
        continue
      c = (nums[i] + nums[i + 1] - 1) // nums[i + 1]
      res += c - 1
      nums[i] = nums[i] // c
    return res

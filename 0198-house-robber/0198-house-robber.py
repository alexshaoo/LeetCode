class Solution:
  def rob(self, nums: List[int]) -> int:
    n = len(nums)
    if n == 1: 
      return nums[0]
    if n == 2: 
      return max(nums[0], nums[1])
    dp = [0] * n
    for house, money in enumerate(nums):
        dp[house] = money + max(dp[house-2], dp[house-3])
    # print(dp)
    return max(dp[-1], dp[-2])
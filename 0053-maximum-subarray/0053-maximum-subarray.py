class Solution:
  def maxSubArray(self, nums: List[int]) -> int:
    n = len(nums)
    dp = [-float('inf') for _  in range(n)]
    dp[0] = nums[0]
    ans = dp[0]
    for i in range(1, n):
      dp[i] = max(0, dp[i-1]) + nums[i]
      ans = max(ans, dp[i])
    return ans
    
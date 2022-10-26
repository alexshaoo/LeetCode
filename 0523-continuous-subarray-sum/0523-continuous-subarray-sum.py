class Solution:
  def checkSubarraySum(self, nums: List[int], k: int) -> bool:
    dp = {}
    kk = 0
    for num in nums:
      if (kk-num) % k in dp: 
        return True
      dp[kk % k] = 1;
      kk -= num
    return False
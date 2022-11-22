class Solution:
  def numSquares(self, n: int) -> int:
    dp = [0] * (n+1)
    for i in range(1,n+1):
      sqrt = int(i**0.5)
      dp[i] = 1+min([dp[i-j*j] for j in range(1,sqrt+1)])
    return dp[n]

class Solution:
  def numSquares(self, n: int) -> int:
    MAX = int(1e5+1)
    squares = [i*i for i in range(1, int(n**0.5)+1)]
    dp = [float('inf')] * (n + 1)
    for square in squares:
      dp[square] = 1
      for i in range(square+1, n+1):
        dp[i] = min(dp[i], dp[i-square] + 1)
    return dp[n]
    
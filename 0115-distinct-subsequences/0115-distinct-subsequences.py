class Solution:
  def numDistinct(self, s: str, t: str) -> int:
    dp = [[0] * len(s) for i in range(len(t))]
    dp[0][0] = int(t[0]==s[0])
    for i in range(1, len(s)):
      dp[0][i] = dp[0][i-1] + int(s[i]==t[0])
    
    
    for i in range(1, len(t)):
      for j in range(i, len(s)):
        if t[i] == s[j]:
          dp[i][j] = dp[i-1][j-1] + dp[i][j-1]
        else:
          dp[i][j] = dp[i][j-1]
    return dp[-1][-1]
class Solution:
  def numDecodings(self, s: str) -> int:

    l = len(s)

    dp = [0 for _ in range(l)] 

    for i in range(l): 
      if s[i] != '0': 
        if i-1 >= 0:
          dp[i] += dp[i-1]
        else:
          dp[i] += 1
      if i-1 >= 0:
        if 10 <= int(s[i-1:i+1]) <= 26: 
          if i-2 >= 0:
            dp[i] += dp[i-2]
          else:
            dp[i] += 1

    return dp[l-1]
    
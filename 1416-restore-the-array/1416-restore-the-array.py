class Solution:
  def numberOfArrays(self, s: str, k: int) -> int:
    n, mod = len(s), 10**9+7
    @lru_cache(None)
    def dfs(i):
      if i == 0:
        return 1
      total = 0
      for j in range(i-1,-1,-1):
        if s[j] == "0": 
          continue
        elif int(s[j:i]) <= k:
          total += dfs(j)%mod
        elif int(s[j:i]) > k:
          break
      return total
    return dfs(n)%mod
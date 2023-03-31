class Solution:
  def ways(self, pizza: List[str], k: int) -> int:
    m, n, mod = len(pizza), len(pizza[0]), 10**9+7
    matrix = [[0 if c=='.' else 1 for c in l] for l in pizza]
    def A(i, j): return matrix[i][j] if 0<=i<m and 0<=j<n else 0
    for i in range(m-1, -1, -1):
      for j in range(n-1, -1, -1):
        matrix[i][j] += (A(i+1, j) + A(i, j+1) - A(i+1, j+1))
    @lru_cache(None)
    def dp(i, j, cut):
      if cut==0: return int(A(i, j) > 0)
      ans = 0
      for h in range(i+1, m): # cut horizontally
        if A(i, j) - A(h, j) > 0: ans += dp(h, j, cut - 1)
      for v in range(j+1, n): # cut vertically
        if A(i, j) - A(i, v) > 0: ans += dp(i, v, cut - 1)
      return ans%mod
    return dp(0, 0, k-1)


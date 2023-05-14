class Solution:
  def maxScore(self, nums: List[int]) -> int:
    @lru_cache(None)
    def dfs(i: int, mask: int) -> int:
      if i > len(nums) / 2:
        return 0
      res = 0
      for j in range(len(nums)):
        for k in range(j + 1, len(nums)):
          size = (1 << j) + (1 << k)
          if not mask & size:
            res = max(res, i * gcd(nums[j], nums[k]) + dfs(i + 1, mask + size))
      return res
    return dfs(1, 0)
class Solution:
  def trap(self, height: List[int]) -> int:
    n = len(height)
    l, r = 0, n-1
    lm, rm = 0, 0
    res = 0
    while l < r:
      lm, rm = max(lm, height[l]), max(rm, height[r])
      if height[l] < height[r]:
        res += (lm - height[l])
        l += 1
      else:
        res += (rm - height[r])
        r -= 1
    return res

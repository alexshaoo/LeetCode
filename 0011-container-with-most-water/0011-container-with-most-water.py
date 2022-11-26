class Solution:
  def maxArea(self, height: List[int]) -> int:
    l = 0
    r = len(height)-1
    m = 0
    while l < r:
      m = max(m, (r-l) * min(height[l], height[r]))
      if height[l] < height[r]: 
        l += 1
      else: 
        r -= 1
    return m
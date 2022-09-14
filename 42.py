class Solution:
  def trap(self, height: List[int]) -> int:

    l = 0
    r = len(height) - 1

    ans = 0

    min_height = 0

    while l < r:

      while l < r and height[l] <= min_height:
        ans += (min_height - height[l])
        l += 1

      while l < r and height[r] <= min_height:
        ans += (min_height - height[r])
        r -= 1

      min_height = min(height[l], height[r])

    return ans

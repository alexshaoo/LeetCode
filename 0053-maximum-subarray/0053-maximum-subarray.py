class Solution:
  def maxSubArray(self, nums: List[int]) -> int:
    n = len(nums)
    if all([num <= 0 for num in nums]):
      return max(nums)
    l, r = 0, 0
    mx, sm = 0, 0
    while r < n:
      sm += nums[r]
      if sm < 0:
        sm = 0
        l = r
      else:
        mx = max(mx, sm)
      r += 1
    return mx
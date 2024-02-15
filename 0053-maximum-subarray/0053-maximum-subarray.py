class Solution:
  def maxSubArray(self, nums: List[int]) -> int:
    n = len(nums)
    if all([num <= 0 for num in nums]):
      return max(nums)
    mx, sm = 0, 0
    for num in nums:
      sm = max(0, sm + num)
      mx = max(mx, sm)
    return mx
class Solution:
  def findPeakElement(self, nums: List[int]) -> int:
    MIN = -float('inf')
    nums = [MIN] + nums + [MIN]
    n = len(nums)
    l = 1
    r = n-2
    while l <= r:
      m = l + (r-l)//2
      # print(nums[m-1], nums[m], nums[m+1])
      if nums[m+1] > nums[m]:
        l = m+1
      elif nums[m-1] > nums[m]:
        r = m-1
      else:
        return m-1
      # print(l, r)
    return 0
    
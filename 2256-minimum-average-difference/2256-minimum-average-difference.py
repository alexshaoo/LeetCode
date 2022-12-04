class Solution:
  def minimumAverageDifference(self, nums: List[int]) -> int:
    tot = sum(nums)
    n = len(nums)
    return min(((abs(s//(i+1)-((tot-s)//(n-i-1) if i != n-1 else 0))), i) for i,s in enumerate(accumulate(nums)))[1]
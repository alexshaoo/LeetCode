class Solution:
  def findErrorNums(self, nums: List[int]) -> List[int]:
    n = len(nums)
    s = sum(nums)
    sm = sum(set(nums))
    return [s - sm, sum(range(1, n+1)) - sm]
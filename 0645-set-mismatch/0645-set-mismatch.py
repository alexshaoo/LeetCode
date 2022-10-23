class Solution:
  def findErrorNums(self, nums: List[int]) -> List[int]:
    n = len(nums)
    s= n*(n+1) /2
    d = sum(nums) - sum(set(nums))
    (m)= int(s- sum(set(nums)))
    return [d,m]
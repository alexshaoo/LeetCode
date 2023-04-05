class Solution:
  def minimizeArrayValue(self, nums: List[int]) -> int:
    ans,ps = -1,[0]
    for num in nums:
      ps.append(ps[-1]+num)
    for i in range(1,len(nums)+1):
      ans = max(ans, ceil(ps[i]/i))
    return ans
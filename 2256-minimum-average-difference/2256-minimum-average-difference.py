class Solution:
  def minimumAverageDifference(self, nums: List[int]) -> int:
    l = len(nums)
    ps = [0]
    for num in nums:
      ps.append(num + ps[-1])
    mi, m = -1, inf
    for i in range(1, l):
      # print(ps[i], ps[l]-ps[i], i, l-i)
      d = abs(ps[i]//i-(ps[l]-ps[i])//(l-i))
      if d < m:
        mi = i-1
        m = d
      # print(d)
      i += 1
    if ps[-1]//l < m:
      return l-1
    return mi
class Solution:
  def maxScoreSightseeingPair(self, values: List[int]) -> int:
    l = len(values)
    res = 0
    curr = 0
    for value in values:
      res = max(res, curr + value)
      curr = max(curr, value) - 1
    return res
    
    # dp = [[values[i]+values[j]+i-j for j in range(i+1, l)] for i in range(l-1)]
#     mx = 0
    
#     for gap in range(1, l):
#       m = 0
#       for i in range(l-gap):
#         m = max(m, values[i] + values[i+gap])
#       mx = max(mx, m-gap)
#     return mx

  
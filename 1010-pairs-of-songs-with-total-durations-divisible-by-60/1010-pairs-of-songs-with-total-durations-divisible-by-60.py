class Solution(object):
  def numPairsDivisibleBy60(self, time):
    """
    :type time: List[int]
    :rtype: int
    """
    d = defaultdict(int)
    ans = 0
    for t in time:
      ans += d[(60-t)%60]
      d[t%60] += 1
    return ans
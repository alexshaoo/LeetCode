class Solution:
  def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
    res = []
    for start, end in sorted(intervals + [newInterval]):
      if res and res[-1][1] >= start:
        res[-1][1] = max(res[-1][1], end)
      else:
        res.append([start, end])

    return res
class Solution:
  def minCostConnectPoints(self, points: List[List[int]]) -> int:
    n = len(points)
    points = list(map(lambda l: tuple(l), points))
    b = set(points)
    def md(p1, p2):
      return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]) 
    res = 0
    pq = [(0, points[0])]
    while b:
      # print("LARGEST:", heapq.nlargest(1, pq))
      d, u = heapq.heappop(pq)
      if u not in b:
        continue
      b.remove(u)
      res += d
      for v in b:
        heapq.heappush(pq, (md(u, v), v))
    return res
class Solution:
  def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
    q = [(0, 0), (0, firstPerson)]
    adj = collections.defaultdict(list)
    for u, v, time in meetings:
      adj[u].append((v, time))
      adj[v].append((u, time))
    res = set()
    while q:
      t, u = heapq.heappop(q)
      if u in res: continue
      res.add(u)
      for v, tt in adj[u]:
        if tt >= t:
          heapq.heappush(q, (tt, v))
    return list(res)

class Solution:
  def minimumFuelCost(self, roads: List[List[int]], seats: int) -> int:
    graph = defaultdict(set)
    for u, v in roads:
      graph[u].add(v), graph[v].add(u)
    def dfs(n, dst):
      ppl,ltr = 1,0
      for src in graph[n]:
        if src == dst: 
          continue
        p,l = dfs(src,n)
        ppl += p
        ltr += l
      ltr += (ppl - 1) // seats + 1 
      return ppl, ltr
    return sum(dfs(n,0)[1] for n in graph[0])
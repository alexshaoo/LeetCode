class Solution:
  def possibleBipartition(self, N: int, dislikes: List[List[int]]) -> bool:
    colouring = {i: -1 for i in range(1, N+1)}
    edges = defaultdict(list)
    for a,b in dislikes:
      edges[a].append(b)
      edges[b].append(a)
    def dfs(node, colour):
      if colouring[node] != -1:
        return colouring[node] == colour
      colouring[node] = colour
      for edge in edges[node]:
        if not dfs(edge, 1-colour): 
          return False
      return True
    return all([colouring[node] != -1 or dfs(node, 0) for node in range(1, N+1)])
    
    
    
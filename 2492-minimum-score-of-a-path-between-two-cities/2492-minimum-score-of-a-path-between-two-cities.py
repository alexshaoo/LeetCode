class Solution:
  def minScore(self, n: int, roads: List[List[int]]) -> int:
    parent = [x for x in range(n)]
    def find(x):
      if x == parent[x]: 
        return x
      parent[x] = find(parent[x])
      return parent[x]
    def union(x,y):
      X, Y = find(x), find(y)
      if X == Y: 
        return
      parent[Y] = X
    for a, b, _ in roads:
      union(a-1, b-1)
    return min([D for a,b,D in roads if find(0) == find(a-1)])
        
class Solution:
  def lexicalOrder(self, n: int) -> List[int]:
    res = []
        
    def dfs(curr):
      if curr > n: 
        return
      res.append(curr)
      dfs(10*curr)   
      if (curr+1) % 10 != 0: 
        dfs(curr+1)

    dfs(1)
    return res

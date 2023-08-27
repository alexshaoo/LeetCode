class Solution:
  def canCross(self, stones: List[int]) -> bool:
    if stones[1]!=1: 
      return False 						# the first position has to be 1.
      
    indices = {v:i for i,v in enumerate(stones)}		# Hashmap which stores value and index pairs.
    
    @cache
    def dfs(i,lastStep):
      if i==len(stones)-1: 							# If we reach to the last position, we are done and return True
        return True
      res = False
      for curStep in range(lastStep-1,lastStep+2):	# The 3 neighbor states discussed above
        if stones[i]+curStep in indices and indices[stones[i]+curStep]>i:	# The next position has to occur after the current position.
          res = res or dfs(indices[stones[i]+curStep],curStep)
      return res
    
    return dfs(1,1)
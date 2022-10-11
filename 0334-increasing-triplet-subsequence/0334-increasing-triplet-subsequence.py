class Solution:
  def increasingTriplet(self, nums: List[int]) -> bool:
    
    first, second = inf, inf
        
    for third in nums:
      if second < third: 
        return True
      if third > first: 
        second = third    
      else: 
        first = third 

    return False
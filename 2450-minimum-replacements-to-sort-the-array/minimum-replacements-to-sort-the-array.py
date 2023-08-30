class Solution:
  def minimumReplacement(self, nums: List[int]) -> int:
    ans=0
    prev=10**9+1
    for x in nums[::-1]:
      d=ceil(x/prev)
      ans+=d-1
      prev=x//d

    return ans    

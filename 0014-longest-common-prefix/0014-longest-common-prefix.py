class Solution:
  def longestCommonPrefix(self, strs: List[str]) -> str:
    if not strs: 
      return ""
    mn = min(strs, key=len)
    for i, ch in enumerate(mn):
      for s in strs:
        if s[i] != ch:
          return mn[:i]
    return mn 
        
    
      
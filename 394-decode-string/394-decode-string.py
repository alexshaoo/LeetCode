class Solution:
  def decodeString(self, s: str) -> str:
    def helper(i):
      res = ""
      l = len(s)
      while i < l and s[i] != ']':
        
        # find number of repeated substring
        num = 0
        while s[i].isdigit(): 
          num *= 10
          num += int(s[i])
          i += 1
          
        # get string
        if s[i] == '[': 
          a, b = helper(i+1)
          res += (a*num)
          i = b
        else: res += s[i]
          
        i += 1
        
      return res, i
    return helper(0)[0]
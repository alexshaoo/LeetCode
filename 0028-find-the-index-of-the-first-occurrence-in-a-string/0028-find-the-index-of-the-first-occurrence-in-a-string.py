class Solution:
  def strStr(self, haystack: str, needle: str) -> int:
    # l = len(needle)
    # ll = len(haystack)
    # if l > ll:
    #   return -1
    # v = 0
    # for i in range(l):
    #   v += (ord(haystack[i])-ord(needle[i]))
    # if v == 0 and haystack[:l] == needle:
    #   return 0
    # for i in range(l, ll):
    #   v += (ord(haystack[i])-ord(haystack[i-l]))
    #   if v == 0 and haystack[i-l+1:i+1] == needle:
    #     return i-l+1
    # return -1
    
    # def f(c):
    #   return ord(c)-ord('A')
    # n, h, d, m = len(needle), len(haystack), ord('z')-ord('A')+1, float('inf')
    # if n > h: return -1
    # nd, hash_n, hash_h = d**(n-1), 0, 0   
    # for i in range(n):
    #   hash_n = (d*hash_n+f(needle[i]))%m
    #   hash_h = (d*hash_h+f(haystack[i]))%m            
    # if hash_n == hash_h: return 0        
    # for i in range(1, h-n+1):
    #   # e.g. 10*(1234-1*10**3)+5=2345
    #   hash_h = (d*(hash_h-f(haystack[i-1])*nd)+f(haystack[i+n-1]))%m
    #   if hash_n == hash_h: return i
    # return -1
    
    l1, l2, p1, p2 = len(haystack), len(needle), 0, 0
    while p1 <= l1:
      if p2 == l2:
        return p1-l2
      elif p1 == l1:
        return -1
      if haystack[p1]==needle[p2]:
        p2 += 1
      else:
        p1,p2 = p1-p2,0
      p1 += 1
class Solution:
  def strStr(self, haystack: str, needle: str) -> int:
    l = len(needle)
    ll = len(haystack)
    if l > ll:
      return -1
    v = 0
    for i in range(l):
      v += (ord(haystack[i])-ord(needle[i]))
    if v == 0 and haystack[:l] == needle:
      return 0
    for i in range(l, ll):
      v += (ord(haystack[i])-ord(haystack[i-l]))
      if v == 0 and haystack[i-l+1:i+1] == needle:
        return i-l+1
    return -1
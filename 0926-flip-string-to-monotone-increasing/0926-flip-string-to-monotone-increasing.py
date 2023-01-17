class Solution:
  def minFlipsMonoIncr(self, s: str) -> int:
    l = len(s)
    ans = l
    z = s.count('0')
    o = 0
    
    for i,c in enumerate(s):
      if c == '1':
        o += 1
      else:
        z -= 1
      print(ans, o, z)
      ans = min(ans, z+o)
      
    return min(min(ans, l-s.count('1')), o)
    
    # poss = [0]
    # one = False
    # for i, c in enumerate(s):
    #   if not one and c == '1':
    #     poss.append(i)
    #     one = True
    #   if c == '0':
    #     one = False
    # poss.append(l)
    # ans = int(1e5+1)
    # for p in poss:
    #   c = 0
    #   for i in range(p):
    #     if s[i] == '1':
    #       c += 1
    #   for i in range(p+1, l):
    #     if s[i] == '0':
    #       c += 1
    #   ans = min(ans, c)
    # return ans
    
class Solution:
  def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
    l = len(s)
    c = 0
    total = [0 for _ in range(l+1)]
    
    if s[-1] == '1':
      return False
    
    for i in range(l):
      c += total[i];
      if i == 0 or (c and s[i] == '0'):
        total[min(i + minJump, l)] += 1;
        total[min(i + maxJump + 1, l)] -= 1;
    
    return c;
    
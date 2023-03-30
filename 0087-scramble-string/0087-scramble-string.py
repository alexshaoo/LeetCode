from functools import lru_cache

class Solution:
  # To prevent TLE, use memo to eliminate redundant calculation
  @lru_cache
  def isScramble(self, s1: str, s2: str) -> bool:
    if s1 == s2:
      return True
    for i in range(1, len(s1)):
      l1, r1 = sorted(s1[:i]), sorted(s1[i:])
      if (l1 == sorted(s2[:i]) and r1 == sorted(s2[i:])):
        if self.isScramble(s1[:i], s2[:i]) and self.isScramble(s1[i:], s2[i:]):
          return True
      if (l1 == sorted(s2[-i:]) and r1 == sorted(s2[:-i])):
        if self.isScramble(s1[:i], s2[-i:]) and self.isScramble(s1[i:], s2[:-i]):
          return True
    return False
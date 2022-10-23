class Solution:
  def numSub(self, s: str) -> int:
    return sum(len(ch) * (len(ch)+1) // 2 for ch in s.split('0')) % int(1e9 + 7)
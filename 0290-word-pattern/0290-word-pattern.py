class Solution:
  def wordPattern(self, pattern: str, s: str) -> bool:
    return len(set(pattern)) == len(set(zip(pattern, s.split(" ")))) == len(set(s.split())) and len(pattern) == len(s.split(" "))
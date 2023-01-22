import functools
class Solution:
  @functools.lru_cache(None)
  def partition(self, s: str) -> List[List[str]]:
    return [[]] if not s else [[s[:i]] + x for i in range(1, len(s)+1) for x in self.partition(s[i:]) if s[:i] == s[:i][::-1]]
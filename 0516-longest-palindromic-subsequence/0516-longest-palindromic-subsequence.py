class Solution:
  @lru_cache(None)
  def longestPalindromeSubseq(self, s: str) -> int:
    recurse = lambda i,j: 1 if i==j else 2 + self.longestPalindromeSubseq(s[i+1:j])
    return max((recurse(s.find(ch), s.rfind(ch)) for ch in set(s)), default=0)
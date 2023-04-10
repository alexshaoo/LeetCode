class Solution:
  def isValid(self, s: str) -> bool:
    return s == '' if s == (s:=s.replace('()', '').replace('{}', '').replace('[]', '')) else self.isValid(s)
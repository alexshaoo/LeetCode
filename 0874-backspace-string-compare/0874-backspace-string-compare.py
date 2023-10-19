class Solution:
  def backspaceCompare(self, s: str, t: str) -> bool:
    s1, s2 = deque(), deque()
    for c1 in s:
      if c1 == "#":
        if s1:
          s1.pop()
      else:
        s1.append(c1)
    for c2 in t:
      if c2 == "#":
        if s2:
          s2.pop()
      else:
        s2.append(c2)
    return s1 == s2
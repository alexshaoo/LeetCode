class Solution:
  def wordPattern(self, pattern: str, s: str) -> bool:
    d = {}
    if len(pattern) != len(s.split(" ")):
      return False
    for l,w in zip(pattern, s.split(" ")):
      # print(l, w)
      if l not in d:
        d[l] = w
      else:
        if d[l] != w:
          return False
    # print(d)
    return len(set(d.keys())) == len(set(d.values()))
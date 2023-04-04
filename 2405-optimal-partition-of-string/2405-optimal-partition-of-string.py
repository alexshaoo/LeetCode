class Solution:
  def partitionString(self, s: str) -> int:
    u,c = set(),1
    for ss in s:
      # print(ss,u)
      if ss in u:
        u = set()
        u.add(ss)
        c += 1
        # print("inc")
      else:
        u.add(ss)
    return c
class Solution:
  def minDeletions(self, s: str) -> int:
    d = defaultdict(int)
    for c in s:
      d[ord(c)-97] += 1
    c = 0
    poss = [True for _ in range(100001)]
    for v in d.values():
      if poss[v]:
        poss[v] = False
      else:
        c += 1
        for i in range(v-1, 0, -1):
          if poss[i]:
            poss[i] = False
            break
          c += 1
      # print(poss)
    return c
        
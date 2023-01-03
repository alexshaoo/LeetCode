class Solution:
  def minDeletionSize(self, strs: List[str]) -> int:
    l = len(strs)
    ll = len(strs[0])
    c = 0
    for i in range(ll):
      lst = [strs[j][i] for j in range(l)]
      if [strs[j][i] for j in range(l)] != sorted([strs[j][i] for j in range(l)]):
        c += 1
    return c
      
class Solution:
  def minimumRounds(self, tasks: List[int]) -> int:
    c = Counter(tasks)
    if any([v==1 for v in c.values()]):
      return -1
    ans = 0
    for v in c.values():
      if v%3 == 0:
        ans += v//3
      elif v%3 == 1:
        ans += 2+(v-4)//3
      else:
        ans += 1+(v-2)//3
    return ans
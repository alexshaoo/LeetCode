class Solution:
  def totalFruit(self, fruits: List[int]) -> int:
    n = len(fruits)
    l = 0
    ans = 0
    cnt = Counter()
    for r, t in enumerate(fruits):
      cnt[t] += 1
      while len(cnt) > 2:
        cnt[fruits[l]] -= 1
        if cnt[fruits[l]] == 0:
          cnt.pop(fruits[l])
        l += 1
      ans = max(ans, r - l + 1)
    return ans
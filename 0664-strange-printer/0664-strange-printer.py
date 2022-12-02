class Solution(object):
    def strangePrinter(self, s):
        memo = dict()
        def h(s):
          if not s:
            return 0
          if s in memo:
            return memo[s]
          c = h(s[0:-1]) + 1
          for i, ch in enumerate(s[:-1]):
            if ch == s[-1]:
              c = min(c, h(s[0:i]) + h(s[i:-1]))
          memo[s] = c
          return c
        return h(s)
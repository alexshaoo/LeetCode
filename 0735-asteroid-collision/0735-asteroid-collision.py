class Solution:
  def asteroidCollision(self, asteroids: List[int]) -> List[int]:
    s = deque()
    i = 0
    n = len(asteroids)
    while i < n:
      if s and s[-1] > 0 and asteroids[i] < 0:
        if s[-1] == abs(asteroids[i]):
          s.pop()
          i += 1
        elif s[-1] > abs(asteroids[i]):
          i += 1
        else:
          s.pop()
      else:
        s.append(asteroids[i])
        i += 1
    return s
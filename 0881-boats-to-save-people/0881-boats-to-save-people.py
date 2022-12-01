class Solution:
  def numRescueBoats(self, people: List[int], limit: int) -> int:
    l = len(people)
    people.sort()
    l, r, b = 0, l-1, 0
    while l <= r:
      if people[l] + people[r] <= limit:
        l += 1
        r -= 1
      else:
        r -= 1
      b += 1
    return b
class Solution:
  def zeroFilledSubarray(self, nums: List[int]) -> int:
    nums += [1]
    s = []
    c = 0
    for num in nums:
      if num == 0:
        c += 1
      else:
        if c != 0:
          s.append(c)
          c = 0
    return sum([n*(n+1)//2 for n in s])
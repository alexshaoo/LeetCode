class Solution:
  def arraySign(self, nums: List[int]) -> int:
    if 0 in nums:
      return 0
    n = 0
    for num in nums:
      if num < 0:
        n += 1
    return -1 if n % 2 == 1 else 1
class Solution:
  def arraySign(self, nums: List[int]) -> int:
    product = 1
    if 0 in nums:
      return 0
    for num in nums:
      if num < 0:
        product = product * -1
    return product
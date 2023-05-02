class Solution:
    def arraySign(self, nums: List[int]) -> int:
        n = 0
        for num in nums:
          if num == 0:
            return 0
          if num < 0:
            n += 1
        return -1 if n % 2 == 1 else 1
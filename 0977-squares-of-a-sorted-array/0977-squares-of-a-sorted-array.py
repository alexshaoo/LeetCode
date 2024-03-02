class Solution:
  def sortedSquares(self, nums: List[int]) -> List[int]:
    d = {}
    for i in range(int(1e4)+1):
      d[i**2] = 0
    for num in nums:
      d[num**2] += 1
    ans = []
    for k, v in d.items():
      if v != 0:
        ans = ans + [k] * v
    return ans
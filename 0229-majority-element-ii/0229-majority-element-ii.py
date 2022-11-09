class Solution:
  def majorityElement(self, nums: List[int]) -> List[int]:
    if not nums:
      return []
    c1, c2, n1, n2 = 0, 0, None, None
    for num in nums:
      if num == n1:
        c1 += 1
      elif num == n2:
        c2 += 1
      elif c1 == 0:
        c1, n1 = 1, num
      elif c2 == 0:
        c2, n2 = 1, num
      else:
        c1, c2 = c1-1, c2-1
    return [n for n in (n1, n2) if nums.count(n) > len(nums) // 3]
  
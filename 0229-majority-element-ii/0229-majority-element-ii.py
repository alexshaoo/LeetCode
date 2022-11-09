class Solution:
  def majorityElement(self, nums: List[int]) -> List[int]:
    c1, c2, n1, n2 = 0, 0, 1, 0 
    for num in nums:
      if num == n1:
        c1 += 1
      elif num == n2:
        c2 += 1
      elif c1 == 0:
        n1 = num
        c1 = 1
      elif c2 == 0:
        n2 = num
        c2 = 1
      else:
        c1 -= 1
        c2 -= 1
    print(c1, c2, n1, n2)
    return [n for n in [n1, n2] if nums.count(n) > len(nums) // 3]
  
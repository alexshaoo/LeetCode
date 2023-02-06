class Solution:
  def shuffle(self, nums: List[int], n: int) -> List[int]:
    return [x for y in zip(nums[:n], nums[n:]) for x in y]
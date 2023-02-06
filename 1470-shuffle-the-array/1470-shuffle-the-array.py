class Solution:
  def shuffle(self, nums: List[int], n: int) -> List[int]:
    return [item for sublist in zip(nums[:n], nums[n:]) for item in sublist]
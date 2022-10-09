class Solution:
  def threeSumClosest(self, nums: List[int], target: int) -> int:
    # two pointer
    nums.sort()
    s = len(nums)
    ans = sum(nums[:3])
    diff = 100000
    for i in range(s-2):
      if i > 0 and nums[i-1] == nums[i]:
        continue
      l = i+1
      r = s-1
      while l < r:
        sm = nums[i] + nums[l] + nums[r]
        if sm == target:
          return target
        if abs(sm-target) < abs(ans-target):
          ans = sm
        if sm < target:
          l += 1
        else:
          r -= 1
    return ans
    
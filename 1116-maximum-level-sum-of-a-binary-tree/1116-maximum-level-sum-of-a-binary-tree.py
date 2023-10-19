# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  def maxLevelSum(self, root: Optional[TreeNode]) -> int:
    levels = []
    def h(r, x):
      if not r:
        return
      if x >= len(levels):
        levels.append(r.val)
      else:
        levels[x] += r.val
      h(r.left, x+1)
      h(r.right, x+1)
    h(root, 0)
    mx, i = levels[0], 0
    for ind, level in enumerate(levels):
      if level > mx:
        i = ind
        mx = level
    return i+1
        
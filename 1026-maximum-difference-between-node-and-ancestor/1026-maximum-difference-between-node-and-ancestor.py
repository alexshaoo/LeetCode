# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  def helper(self, root, mi, ma):
    if not root:
      return ma-mi
    mi = min(mi, root.val)
    ma = max(ma, root.val)
    return max(self.helper(root.left, mi, ma), self.helper(root.right, mi, ma))
  def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
    return self.helper(root, int(1e5), 0)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  def maxAncestorDiff(self, root: Optional[TreeNode], mi=int(1e5), ma=0) -> int:
    if not root:
      return ma-mi
    mi = min(mi, root.val)
    ma = max(ma, root.val)
    return max(self.maxAncestorDiff(root.left, mi, ma), self.maxAncestorDiff(root.right, mi, ma))
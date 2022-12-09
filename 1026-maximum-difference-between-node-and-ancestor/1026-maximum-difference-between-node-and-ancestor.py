# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  def maxAncestorDiff(self, root: Optional[TreeNode], mi=int(1e5), ma=0) -> int:
    return ma-mi if not root else max(self.maxAncestorDiff(root.left, min(mi, root.val), max(ma, root.val)), self.maxAncestorDiff(root.right, min(mi, root.val), max(ma, root.val)))
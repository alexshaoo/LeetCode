# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  def minDiffInBST(self, root: Optional[TreeNode]) -> int:
    inOrder = lambda n: inOrder(n.left) + [n.val] + inOrder(n.right) if n else []
    vals = inOrder(root)
    return min(a - b for a, b in zip(vals[1:], vals))
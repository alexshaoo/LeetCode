# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
    def depth(x):
      if not x or not (x.left or x.right): 
        return (bool(x), x)
      (ld,lx), (rd,rx) = depth(x.left), depth(x.right)
      if ld == rd:
        return (1+ld,x)
      return max((1+ld,lx), (1+rd,rx))
    return depth(root)[1]
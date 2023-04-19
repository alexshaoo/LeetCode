# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  def longestZigZag(self, root: TreeNode, t=-1, p=None) -> int:
    return max(self.longestZigZag(root.left, 0 if p == 0 else t+1, 0), self.longestZigZag(root.right, 0 if p == 1 else t+1, 1)) if root else t
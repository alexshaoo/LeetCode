# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  def find(self, root: Optional[TreeNode], k: int, want: List[int]) -> bool:
    if root == None:
      return False
    if root.val in want:
      return True
    want.append(k - root.val)
    return self.find(root.left, k, want) or self.find(root.right, k, want)
  def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
    return self.find(root, k, [])
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  def add(self, root: Optional[TreeNode], val: int, depth: int, left: bool) -> Optional[TreeNode]:
    if depth != 1:
      if root == None:
        return 
      root.left = self.add(root.left, val, depth-1, True)
      root.right = self.add(root.right, val, depth-1, False)
      return root
    
    if left:
      return TreeNode(val, root, None)
    return TreeNode(val, None, root)
  def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
    return self.add(root, val, depth, True)
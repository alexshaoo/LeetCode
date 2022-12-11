# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  def maxPathSum(self, root: Optional[TreeNode]) -> int:
    def dfs(node):
      if not node: 
        return (0, -inf)
      (h1, p1), (h2, p2) = dfs(node.left), dfs(node.right)
      return max(h1, h2, 0) + node.val, max(p1, p2, max(h1,0) + max(h2,0) + node.val)
    return dfs(root)[1]
  # lambda self, node, res=(lambda x,y:y): (lambda h1,p1,h2,p2: res(max(h1,h2,0) + node.val, max(p1, p2, max(h1,0) + max(h2,0) + node.val)))(*self.maxPathSum(node.left, lambda *x:x), *self.maxPathSum(node.right, lambda *x:x)) if node else res(0, -inf)
      
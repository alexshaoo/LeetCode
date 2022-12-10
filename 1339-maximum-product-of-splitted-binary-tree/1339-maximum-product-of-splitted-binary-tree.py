# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  def maxProduct(self, root: Optional[TreeNode]) -> int:
    fn = lambda n: ans.append(a := fn(n.left) + fn(n.right) + n.val) or a if n else 0
    ans = []
    s = fn(root) or ans[-1]
    return max((s - n) * n for n in ans) % (10 ** 9 + 7)
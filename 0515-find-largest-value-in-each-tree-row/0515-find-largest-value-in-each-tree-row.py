# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  def largestValues(self, root: Optional[TreeNode]) -> List[int]:
    rows = []
    def calc(root, row):
      if not root:
        return
      if row == len(rows):
        rows.append(root.val)
      else:
        rows[row] = max(root.val, rows[row])
      calc(root.left, row+1)
      calc(root.right, row+1)
    calc(root, 0)
    return rows

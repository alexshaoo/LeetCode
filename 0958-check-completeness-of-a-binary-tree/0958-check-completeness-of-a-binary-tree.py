# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
  def isCompleteTree(self, root: Optional[TreeNode]) -> bool:
    # q = deque([root])
    # while q[0] != None:
    #   node = q.popleft()
    #   q.extend([node.left, node.right])
    # return len(list(filter(None, q))) == 0
    deq = deque([root])
    while deq:
      curr = deq.popleft()
      if curr == None:
        return not any(deq)
      deq.append(curr.left)
      deq.append(curr.right)
    return True
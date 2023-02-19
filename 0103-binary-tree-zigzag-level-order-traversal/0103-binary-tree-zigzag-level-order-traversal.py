class Solution:
  def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
    ans, level = [], [root]
    while root and level:
      ans.append([n.val for n in level if n])
      if len(ans) % 2 == 0:
        ans[-1].reverse()
      level = [k for n in level for k in (n.left, n.right) if k]
    return ans
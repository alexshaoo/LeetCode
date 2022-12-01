# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
  def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
    c, tmp = head, ListNode(0)
    while c:
      n = tmp
      while n.next and n.next.val < c.val:
        n = n.next
      c.next, n.next, c, n = n.next, c, c.next, n.next
    return tmp.next
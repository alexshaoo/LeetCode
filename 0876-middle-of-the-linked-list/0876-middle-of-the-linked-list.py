# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
  def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
    c, n = head, head
    while n and n.next:
      c = c.next
      n = n.next.next
    return c
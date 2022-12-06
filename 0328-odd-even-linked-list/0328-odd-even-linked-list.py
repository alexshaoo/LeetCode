# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
  def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
    if not head or not head.next: 
      return head
    r, odd, p, head = head, head, head.next, head.next.next
    while head:
      odd.next, head.next, p.next = head, odd.next, head.next
      p, odd, head = p.next, head, p.next and p.next.next
    return r
    
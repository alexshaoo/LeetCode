# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
  def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
    if head == None or head.next == None:
      return head
    h = head.next
    l = head
    r = h
    l.next, r.next = r.next, l
    while l.next and l.next.next:
      prev = l
      l = l.next
      r = l.next
      l.next, r.next = r.next, l
      prev.next = r
    return h
    
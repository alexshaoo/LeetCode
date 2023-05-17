# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
  def pairSum(self, head: Optional[ListNode]) -> int:
    def reverse(head):
      prev, curr = None, head
      while curr:
        next_node = curr.next
        curr.next = prev
        prev, curr = curr, next_node
      return prev
    slow, fast = head, head
    while fast:
      slow = slow.next
      fast = fast.next.next
    first = head
    second = reverse(slow)
    max_so_far = 0
    while second:
      summ = first.val + second.val
      max_so_far = max(max_so_far, summ)
      first, second = first.next, second.next
    return max_so_far
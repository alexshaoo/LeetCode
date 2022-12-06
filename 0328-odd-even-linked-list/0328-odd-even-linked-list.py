# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution: oddEvenList = lambda _,r: (h := [None]*2, t := [None]*2, all((setitem(h, i, x), setitem(t, i, x)) if h[i] == None else (setattr(t[i], 'next', x), setitem(t, i, x)) for i, x in zip(cycle(range(2)),takewhile(lambda x:x, accumulate(repeat(r), lambda z,_:z.next)))), setattr(t[0], 'next', h[1]) if t[0] else None, setattr(t[1], 'next', None) if t[1] else None, r)[-1]
    
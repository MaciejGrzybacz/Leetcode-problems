# https://leetcode.com/problems/add-two-numbers/
from typing import Optional
class ListNode:
   def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        rl = ListNode((l1.val + l2.val) % 10)
        rest = (l1.val + l2.val) // 10
        l1 = l1.next
        l2 = l2.next
        pivot = rl
        while l1 is not None and l2 is not None:
            s = l1.val + l2.val
            pivot.next = ListNode((s + rest) % 10)
            rest = (s + rest) // 10
            pivot = pivot.next
            l1 = l1.next
            l2 = l2.next

        while l1 is not None:
            s = l1.val
            pivot.next = ListNode((s + rest) % 10)
            rest = (s + rest) // 10
            pivot = pivot.next
            l1 = l1.next

        while l2 is not None:
            s = l2.val
            pivot.next = ListNode((s + rest) % 10)
            rest = (s + rest) // 10
            pivot = pivot.next
            l2 = l2.next

        if rest:
            pivot.next = ListNode(1)
        return rl


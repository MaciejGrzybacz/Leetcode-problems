# https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/
from typing import Optional


# Definition for singly-linked list.
class ListNode:
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        if head.next.next == None:
            return head.val + head.next.val

        slow = fast = head
        while slow and fast:
            slow = slow.next
            fast = fast.next.next

        prev = None
        while slow:
            temp = slow.next
            slow.next = prev
            prev = slow
            slow = temp

        max_sum = -float(inf)
        while head and prev:
            max_sum = max(max_sum, head.val + prev.val)
            head = head.next
            prev = prev.next
        return max_sum

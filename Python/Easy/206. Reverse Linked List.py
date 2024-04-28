# https://leetcode.com/problems/reverse-linked-list/description/
from typing import Optional


# Definition for singly-linked list.
class ListNode:
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        tmp1 = head
        if head is None:
            return None
        tmp2 = head.next
        if tmp2 is None:
            return head
        if tmp2.next == None:
            tmp2.next = tmp1
            tmp1.next = None
            return tmp2

        tmp1.next = None
        tmp3 = tmp2.next
        while tmp3 is not None:
            tmp2.next = tmp1
            tmp1 = tmp2
            tmp2 = tmp3
            tmp3 = tmp3.next

        tmp2.next = tmp1
        return tmp2


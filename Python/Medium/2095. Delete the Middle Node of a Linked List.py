# https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/
from typing import Optional


# Definition for singly-linked list.
class ListNode:
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head.next:
            return None
        if not head.next.next:
            head.next=None
            return head
        slow=ListNode()
        slow.next, fast=head, head
        while fast and fast.next:
            slow=slow.next
            fast=fast.next.next
        slow.next=slow.next.next
        return head
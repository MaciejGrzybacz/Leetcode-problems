# https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if head.next==None:
            return None
        if head.next.next==None and n==2:
            head=head.next
            return head
        fast=head
        for _ in range(n+1):
            if not fast:
                head=head.next
                return head
            fast=fast.next
        slow= head
        while fast:
            fast=fast.next
            slow=slow.next
        if n==0:
            return head
        if n==1:
            slow.next=None
            return head
        slow.next=slow.next.next
        return head
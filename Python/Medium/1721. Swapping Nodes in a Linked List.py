# https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        left,right,curr=head, head, head
        counter=1

        while curr:
            if counter<k:
                left=left.next
            if counter>k:
                right=right.next
            curr=curr.next
            counter+=1

        tmp=right.val
        right.val=left.val
        left.val=tmp

        return head
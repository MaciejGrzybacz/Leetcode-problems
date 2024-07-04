# https://leetcode.com/problems/merge-nodes-in-between-zeros/description/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        tmpHead = ListNode()
        tmpCurr = tmpHead
        tmpSum = 0

        while head:
            if head.val == 0 and tmpSum:
                tmpCurr.next = ListNode(tmpSum)
                tmpCurr = tmpCurr.next
                tmpSum = 0
            else:
                tmpSum += head.val
            head = head.next

        return tmpHead.next 

        
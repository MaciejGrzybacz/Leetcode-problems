# https://leetcode.com/problems/merge-two-sorted-lists/description/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if list1 == None and list2 == None:
            return list1
        elif list1 == None and not list2 == None:
            return list2
        elif not list1 == None and list2 == None:
            return list1

        head = tmp = None
        if list1.val < list2.val:
            head = tmp = list1
            list1 = list1.next
        else:
            head = tmp = list2
            list2 = list2.next

        while list1 and list2:
            if list1.val < list2.val:
                tmp.next = list1
                list1 = list1.next
            else:
                tmp.next = list2
                list2 = list2.next
            tmp = tmp.next

        if list1 is not None:
            tmp.next = list1
        if list2 is not None:
            tmp.next = list2
        return head




# https://leetcode.com/problems/merge-in-between-linked-lists/description/

# Definition for singly-linked list.
class ListNode:
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next


class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        tmp1 = list1
        i = 1
        while tmp1:
            if i == a:
                break
            i += 1
            tmp1 = tmp1.next
        tmp2 = tmp1
        while tmp2:
            if i == b + 2:
                break
            i += 1
            tmp2 = tmp2.next

        tmp1.next = list2
        tmp3 = list2
        while tmp3.next:
            tmp3 = tmp3.next
        tmp3.next = tmp2

        return list1


// https://leetcode.com/problems/reverse-nodes-in-k-group/description/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    private ListNode kNodesLeft(ListNode head, int k) {
        for (int i = 0; i < k; i++) {
            if (head == null)
                return null;
            head = head.next;
        }
        return head; 
    }

    private ListNode reverseGroup(ListNode head, int k) {
        ListNode prev = null;
        ListNode curr = head;
        for (int i = 0; i < k; i++) {
            ListNode tmp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }

public ListNode reverseKGroup(ListNode head, int k) {
    if (head == null) return null;  

    ListNode kthNode = kNodesLeft(head, k - 1);  
    if (kthNode == null) {
        return head; 
    }

    ListNode nextGroupHead = kthNode.next;  
    kthNode.next = null;  

    ListNode newHead = reverseGroup(head, k); 
    head.next = reverseKGroup(nextGroupHead, k);  

    return newHead;  
}

}

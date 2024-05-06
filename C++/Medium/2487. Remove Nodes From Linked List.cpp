// https://leetcode.com/problems/remove-nodes-from-linked-list/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);
        ListNode* tmp = head;
        ListNode* prev = nullptr; 
        int curr_max = head->val;
        while (tmp) { 
            if (tmp->val >= curr_max) {
                curr_max = tmp->val;
                prev = tmp; 
            } else {
                if (prev) { 
                    prev->next = tmp->next; 
                }
            }
            tmp = tmp->next;
        }
        return reverseList(head);
    }

};
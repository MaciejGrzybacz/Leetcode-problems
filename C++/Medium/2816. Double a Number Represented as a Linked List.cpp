// https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/

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
    ListNode* doubleIt(ListNode* head) {
        head=reverseList(head);
        int rest=0;
        ListNode* tmp=head;
        ListNode* prev=nullptr;
        while(tmp) {
            prev=tmp;
            int new_val=(tmp->val)*2+rest;
            tmp->val=new_val%10;
            rest=new_val/10;
            tmp=tmp->next;
        }
        if(rest) {
            prev->next=new ListNode(rest);
        }
        return reverseList(head);
    }
};
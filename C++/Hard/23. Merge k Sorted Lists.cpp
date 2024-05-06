// https://leetcode.com/problems/merge-k-sorted-lists/description/

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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        else if (lists.size() == 1) return lists[0];
        
        priority_queue<ListNode*, deque<ListNode*>, Compare> pq;
        
        for (auto list : lists) {
            if (list) pq.push(list);
        }
        
        ListNode* head = nullptr;
        ListNode* dummy = nullptr;
        
        while (!pq.empty()) {
            ListNode* tmp = pq.top();
            if (!head) {
                head = tmp;
                dummy = head;
            } else {
                dummy->next = tmp;
                dummy = dummy->next;
            }
            pq.pop();
            if (tmp->next) pq.push(tmp->next);
        }
        
        return head;
    }
};

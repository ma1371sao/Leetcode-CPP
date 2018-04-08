/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    struct cmp {
       bool operator() (ListNode* a, ListNode* b) {
           return a->val > b->val;
       } 
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (auto p : lists)
            if (p)
                pq.push(p);
        ListNode* preHead = new ListNode(0);
        ListNode* p = preHead;
        while (!pq.empty()) {
            p->next = pq.top();
            pq.pop();
            p = p->next;
            if (p->next) pq.push(p->next);
        }
        return preHead->next;
    }
};
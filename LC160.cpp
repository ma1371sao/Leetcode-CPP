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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode* p = headA;
        ListNode* q = headB;
        while (p != q) {
            if (p->next == NULL && q->next == NULL)
                return NULL;
            if (p->next == NULL) p = headB;
            else p = p->next;
            if (q->next == NULL) q = headA;
            else q = q->next;
        }
        return p;
    }
};

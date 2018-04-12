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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* preHead = new ListNode(0);
        preHead->next = head;
        ListNode* p = head;
        ListNode* pre = preHead;
        while (p) {
            if (p->next == NULL || p->next->val != p->val) {
                pre->next = p;
                pre = p;
            }
            int num = p->val;
            for (p = p->next; p && p->val == num; p = p->next);
        }
        pre->next = NULL;
        return preHead->next;
    }
};
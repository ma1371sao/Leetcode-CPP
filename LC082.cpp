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
        if (head == NULL || head->next == NULL) return head;
        ListNode* preHead = new ListNode(0);
        preHead->next = head;
        ListNode* pre = preHead;
        ListNode* p = head;
        while (p) {
            bool doRemove = false;
            while (p->next && p->val == p->next->val) {
                p = p->next;
                doRemove = true;
            }
            if (doRemove) {
                pre->next = p->next;
                p = p->next;
            }
            else {
                pre = p;
                p = p->next;
            }
        }
        return preHead->next;
    }
};
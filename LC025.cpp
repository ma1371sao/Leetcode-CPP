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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int num = 0;
        ListNode* p = head;
        while (p) {
            num++;
            p = p->next;
        }
        num /= k;
        ListNode* preHead = new ListNode(0);
        preHead->next = head;
        ListNode* pre = preHead;
        p = head;
        ListNode* preP = preHead;
        for (int i = 0; i < num; i++) {
            preP = p;
            p = p->next;
            for (int j = 0; j < k - 1; j++) {
                ListNode* nxt = p->next;
                p->next = preP;
                preP = p;
                p = nxt;
            }
            ListNode* tmp = pre->next;
            pre->next->next = p;
            pre->next = preP;
            pre = tmp;
        }
        return preHead->next;
    }
};
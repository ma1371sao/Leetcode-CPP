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
        if (k == 0 || k == 1) return head;
        ListNode* preHead = new ListNode(0);
        preHead->next = head;
        ListNode* p = head;
        ListNode* preGroup = preHead;
        int len = 0;
        while (p) {
            len++;
            p = p->next;
        }
        p = head;
        while (len >= k) {
            ListNode* pre = p;
            p = p->next;
            for (int i = 0; i < k - 1; i++) {
                ListNode* nxt = p->next;
                p->next = pre;
                pre = p;
                p = nxt;
            }
            preGroup->next->next = p;
            ListNode* tmp = preGroup->next;
            preGroup->next = pre;
            preGroup = tmp;
            len -= k;
        }
        ListNode* res = preHead->next;
        delete preHead;
        return res;
    }
};

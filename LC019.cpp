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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* preHead = new ListNode(0);
        preHead->next = head;
        ListNode* p = preHead;
        for (int i = 0; i < n; i++) {
            if (p->next == NULL) return head;
            p = p->next;
        }
        ListNode* preNthNode = preHead;
        while (p->next != NULL) {
            p = p->next;
            preNthNode = preNthNode->next;
        }
        preNthNode->next = preNthNode->next->next;
        return preHead->next;
    }
};
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        int n = 0;
        while (fast) {
            n++;
            fast = fast->next;
        }
        k = k % n;
        if (k == 0) return head;
        fast = head;
        for (int i = 0; i < k; i++)
            fast = fast->next;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        return head;
    }
};
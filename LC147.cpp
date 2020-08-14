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
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return NULL;
        ListNode* preHead = new ListNode();
        preHead->next = head;
        ListNode* q = head;
        while (q->next) {
            ListNode* insertNd = q->next;
            ListNode* i = preHead;
            for (; i != q; i = i->next) {
                if (i->next->val > insertNd->val) {
                    q->next = insertNd->next;
                    insertNd->next = i->next;
                    i->next = insertNd;
                    break;
                }
            }
            if (i == q) {
                q = insertNd;
            }
        }
        ListNode* newHead = preHead->next;
        delete(preHead);
        return newHead;
    }
};

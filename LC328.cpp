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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return NULL;
        ListNode* oddHead = head;
        if (!head->next) return head;
        ListNode* evenHead = head->next;
        ListNode* odd = oddHead;
        ListNode* even = evenHead;
        while (even) {
            ListNode* oddNxt = even->next;
            ListNode* evenNxt = NULL;
            if (even->next) evenNxt = even->next->next;
            if (oddNxt) {
                odd->next = oddNxt;
                even->next = evenNxt;
                odd = oddNxt;
                even = evenNxt;
            } else break;
        }
        odd->next = evenHead;
        return oddHead;
    }
};

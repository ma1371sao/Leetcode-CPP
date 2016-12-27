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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* start = new ListNode(0);
		ListNode* p = l1;
		ListNode* q = l2;
		ListNode* t = start;
		while (p || q) {
			if (p && q) {
				if (p->val <= q->val) {
					t->next = p;
					p = p->next;
				}
				else {
					t->next = q;
					q = q->next;
				}
				t = t->next;
			}
			else if (p) {
				t->next = p;
				break;
			}
			else {
				t->next = q;
				break;
			}
		}
		return start->next;
	}
};
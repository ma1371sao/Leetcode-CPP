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
	ListNode* sortList(ListNode* head) {
		if (!head || head->next == NULL)   return head;
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast->next && fast->next->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		fast = slow;
		slow = slow->next;
		fast->next = NULL;
		ListNode* l1 = sortList(head);
		ListNode* l2 = sortList(slow);
		return Merge(l1, l2);
	}
	ListNode* Merge(ListNode* l1, ListNode* l2) {
		ListNode* start = new ListNode(-1);
		ListNode* p = start;
		while (l1 && l2) {
			if (l1->val <= l2->val) {
				p->next = l1;
				l1 = l1->next;
				p = p->next;
			}
			else {
				p->next = l2;
				l2 = l2->next;
				p = p->next;
			}
		}
		if (l1) {
			p->next = l1;
		}
		if (l2) {
			p->next = l2;
		}
		return start->next;
	}
};
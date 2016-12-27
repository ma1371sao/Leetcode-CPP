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
	ListNode* partition(ListNode* head, int x) {
		if (head == NULL)  return head;
		ListNode* p = head;
		ListNode* start = new ListNode(0);
		start->next = head;
		ListNode* pre = start;
		ListNode* insert;
		int flag = 0;
		while (p) {
			if (!flag && p->val >= x) {
				flag = 1;
				insert = pre;
				pre = p;
				p = p->next;
			}
			else if (flag && p->val<x) {
				pre->next = p->next;
				p->next = insert->next;
				insert->next = p;
				insert = p;
				p = pre->next;
			}
			else {
				pre = p;
				p = p->next;
			}
		}
		return start->next;
	}
};
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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (m>n || m<0 || n<0 || head == NULL)   return head;
		ListNode* start = new ListNode(0);
		start->next = head;
		ListNode* p = head;
		ListNode* pre = start;
		ListNode* q;
		for (int i = 1; i<m; i++) {
			pre = p;
			p = p->next;
		}
		q = p;
		p = p->next;
		for (int i = m; i<n; i++) {
			ListNode* tmp = p->next;
			p->next = q;
			q = p;
			p = tmp;
		}
		pre->next->next = p;
		pre->next = q;
		return start->next;
	}
};
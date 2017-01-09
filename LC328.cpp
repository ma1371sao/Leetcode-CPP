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
	ListNode* oddEvenList(ListNode* head) {
		if (head == NULL || head->next == NULL || head->next->next == NULL)
			return head;
		ListNode* cur = head;
		ListNode* pre = head->next;
		ListNode* p = head->next->next;
		for (; p;) {
			ListNode* nxt;
			if (p->next && p->next->next)
				nxt = p->next;
			else
				nxt = NULL;
			pre->next = p->next;
			p->next = cur->next;
			cur->next = p;
			cur = p;
			pre = nxt;
			if (pre)
				p = pre->next;
			else
				p = NULL;
		}
		return head;
	}
};
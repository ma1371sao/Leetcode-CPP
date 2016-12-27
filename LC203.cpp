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
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* p;
		ListNode* pre;
		if (head == NULL)
			return head;
		while (head && head->val == val)
		{
			head = head->next;
		}
		if (!head)
			return head;
		pre = head;
		p = head->next;
		while (p)
		{
			if (p->val == val)
				pre->next = p->next;
			else
				pre = p;
			p = p->next;

		}
		return head;
	}
};
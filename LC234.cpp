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
	bool isPalindrome(ListNode* head) {
		if (head == NULL)
			return true;
		ListNode *p, *r_head, *pre;
		p = head;
		pre = NULL;
		while (p)
		{
			ListNode *tmp = new ListNode(p->val);
			tmp->next = pre;
			pre = tmp;
			if (p->next == NULL)
				r_head = tmp;
			p = p->next;
		}
		ListNode *q = r_head;
		p = head;
		for (; p; p = p->next, q = q->next)
		{
			if (p->val != q->val)
				return false;
		}
		return true;
	}
};
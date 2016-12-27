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
		ListNode* head = new ListNode(0);
		if (l1 == NULL && l2 == NULL)
			return NULL;
		ListNode* p = head;
		int flag = 1;
		while (l1 && l2)
		{
			if (flag)
				flag = 0;
			else
			{
				p->next = new ListNode(0);
				p = p->next;
			}
			if (l1->val <= l2->val)
			{
				p->val = l1->val;
				l1 = l1->next;
			}
			else
			{
				p->val = l2->val;
				l2 = l2->next;
			}
		}
		if (l1)
		{
			if (flag)
			{
				p->val = l1->val;
				p->next = l1->next;
			}
			else
				p->next = l1;
		}
		if (l2)
		{
			if (flag)
			{
				p->val = l2->val;
				p->next = l2->next;
			}
			else
				p->next = l2;
		}
		return head;
	}
};
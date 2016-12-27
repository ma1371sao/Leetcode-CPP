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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* p1;
		ListNode* p2;
		if (l1 == NULL && l2 == NULL)
			return NULL;
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		ListNode* ans = new ListNode(0);
		ListNode *k = ans;
		int jinwei = 0;
		p1 = l1;
		p2 = l2;
		while (1)
		{
			if (p1 && p2)
			{
				int tmp = p1->val + p2->val + jinwei;
				jinwei = tmp / 10;
				k->val = tmp % 10;
				p1 = p1->next;
				p2 = p2->next;
			}
			else if (p1)
			{
				int tmp = p1->val + jinwei;
				jinwei = tmp / 10;
				k->val = tmp % 10;
				p1 = p1->next;
			}
			else if (p2)
			{
				int tmp = p2->val + jinwei;
				jinwei = tmp / 10;
				k->val = tmp % 10;
				p2 = p2->next;
			}
			if (p1 == NULL && p2 == NULL)
				break;
			else
			{
				k->next = new ListNode(0);
				k = k->next;
			}
		}
		if (jinwei)
		{
			k->next = new ListNode(0);
			k->next->val = jinwei;
		}
		return ans;
	}
};
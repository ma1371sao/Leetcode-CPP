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
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL)
			return head;
		ListNode *p = head;
		ListNode *pre = head;
		while (p != NULL)
		{
			if (p->next == NULL)

				if (p == head)
				{
					ListNode *t_nn = p->next->next;
					ListNode *t_n = p->next;
					ListNode *t = p;
					head = t_n;
					t_n->next = t;
					t->next = t_nn;
					pre = p;
				}
				else
				{
					ListNode *t_nn = p->next->next;
					ListNode *t_n = p->next;
					ListNode *t = p;
					pre->next = t_n;
					t_n->next = t;
					t->next = t_nn;
					pre = p;
				}
			p = p->next;

		}
		return head;
	}
};
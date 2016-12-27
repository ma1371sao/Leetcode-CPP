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
	ListNode* rotateRight(ListNode* head, int k) {
		if (k == 0 || head == NULL)
			return head;
		int n = 1;
		ListNode* p = head;
		while (p->next)
		{
			n++;
			p = p->next;
		}
		ListNode* oriEnd = p;
		k = k%n;
		if (k == 0)
			return head;
		int save = n - k;
		for (p = head; save>1; p = p->next, save--);
		oriEnd->next = head;
		head = p->next;
		p->next = NULL;
		return head;
	}
};
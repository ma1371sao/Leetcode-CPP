class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int count = 1;
		ListNode *p;
		for (p = head; p->next; p = p->next)
			count++;
		if (count == 1)
		{
			head = NULL;
			return head;
		}
		int k = count - n + 1;
		if (k == 1)
		{
			head = head->next;
			return head;
		}
		p = head;
		for (int i = 1; i<k - 1; i++, p = p->next);
		if (p->next->next == NULL)
			p->next = NULL;
		else
		{
			p->next = p->next->next;
		}
		return head;
	}
};
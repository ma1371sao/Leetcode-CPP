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
	ListNode* reverseList(ListNode* head) {
		if (!head)
			return head;
		if (head->next == NULL)
			return head;
		ListNode *p = head->next;
		ListNode *pre = head;
		head->next = NULL;
		while (p)
		{
			ListNode* tmp = p->next;
			p->next = pre;
			pre = p;
			p = tmp;
		}
		head = pre;
		return head;
	}
};
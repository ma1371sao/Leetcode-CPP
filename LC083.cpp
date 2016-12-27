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
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head)
			return head;
		ListNode* p = head->next;
		ListNode* pre = head;
		int temp = pre->val;
		while (p)
		{
			if (temp == p->val)
			{
				pre->next = p->next;
				p = pre->next;
			}
			else
			{
				pre = p;
				p = p->next;
				temp = pre->val;
			}
		}
		return head;
	}
};
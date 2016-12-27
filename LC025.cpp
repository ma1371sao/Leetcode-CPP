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
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == NULL)
			return head;
		if (k == 1 || k == 0)
			return head;
		ListNode* ln[100000];
		ListNode* nxt;
		ListNode* pre = head;
		int num = 0;
		ListNode* p = head;
		while (p)
		{
			ln[num] = p;
			if (num == k - 1)
			{
				nxt = ln[k - 1]->next;
				for (int i = k - 1; i>0; i--)
				{
					ln[i]->next = ln[i - 1];
				}
				if (pre == head)
					head = ln[k - 1];
				else
					pre->next = ln[k - 1];
				pre = ln[0];
				ln[0]->next = nxt;
				num = 0;
				p = pre->next;
			}
			else
			{
				num++;
				p = p->next;
			}
		}
		return head;
	}
};
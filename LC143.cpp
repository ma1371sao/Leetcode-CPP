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
	void reorderList(ListNode* head) {
		if (head == NULL || head->next == NULL || head->next->next == NULL)    return;
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast->next && fast->next->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		fast = slow->next->next;
		ListNode* pre = slow->next;
		while (fast) {
			ListNode* tmp = fast->next;
			fast->next = pre;
			pre = fast;
			fast = tmp;
		}
		slow->next->next = NULL;
		slow->next = NULL;
		ListNode* p = head;
		ListNode* q = pre;
		while (p && q) {
			ListNode* tmp1 = p->next;
			ListNode* tmp2 = q->next;
			p->next = q;
			q->next = tmp1;
			p = tmp1;
			q = tmp2;
		}
	}
};
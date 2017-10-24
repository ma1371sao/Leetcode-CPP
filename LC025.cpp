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
		ListNode* newHead = new ListNode(0);
		newHead->next = head;
		ListNode* p = head;
		ListNode* preHead = newHead;
		int len = 0;
		while (p) {
			len++;
			p = p->next;
		}
		if (k == 1 || len < k) return head;
		p = head;
		for (int i = 0; i + k <= len; i += k) {
			ListNode* newPreHead = p;
			ListNode* pre = p;
			p = p->next;
			for (int j = 0; j < k - 1; j++) {
				ListNode* nxt = p->next;
				p->next = pre;
				pre = p;
				p = nxt;
			}
			preHead->next = pre;
			preHead = newPreHead;
		}
		preHead->next = p;
		return newHead->next;
	}
};
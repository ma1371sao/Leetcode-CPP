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
		ListNode* preHead = new ListNode(0);
		preHead->next = head;
		ListNode* p = head;
		ListNode* pre = preHead;
		while (p && p->next) {
			ListNode* nxtPair = p->next->next;
			p->next->next = p;
			pre->next = p->next;
			pre = p;
			p = nxtPair;
		}
		pre->next = p;
		return preHead->next;
	}
};
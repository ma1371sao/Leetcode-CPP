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
		if (head == NULL)  return head;
		unordered_map<int, ListNode*> preVal;
		ListNode* start = new ListNode(0);
		start->next = head;
		ListNode* p = head->next;
		preVal[head->val] = start;
		ListNode* pre = head;
		while (p) {
			if (preVal.find(p->val) == preVal.end()) {
				preVal[p->val] = pre;
				pre = p;
				p = p->next;
			}
			else {
				pre->next = p->next;
				if (preVal[p->val] != NULL) {
					if (preVal[p->val]->next == pre)   pre = preVal[p->val];
					preVal[p->val]->next = preVal[p->val]->next->next;
					preVal[p->val] = NULL;
				}
				p = p->next;
			}
		}
		return start->next;
	}
};
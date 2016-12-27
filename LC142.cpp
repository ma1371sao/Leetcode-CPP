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
	ListNode *detectCycle(ListNode *head) {
		unordered_map<ListNode*, bool> hash;
		if (!head)
			return NULL;
		ListNode* p = head;
		while (p) {
			if (hash.find(p) != hash.end())
				return p;
			else
				hash[p] = true;
			p = p->next;
		}
		return NULL;
	}
};
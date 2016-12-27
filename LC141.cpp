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
	bool hasCycle(ListNode *head) {
		if (!head || head->next == NULL)   return false;
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast->next != NULL && fast->next->next != NULL) {
			if (fast->next->next == slow->next)
				return true;
			fast = fast->next->next;
			slow = slow->next;
		}
		return false;
	}
};
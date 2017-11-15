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
	bool isPalindrome(ListNode* head) {
		if (head == NULL || head->next == NULL) return true;
		ListNode* slow = head;
		ListNode* fast = head;
		ListNode* pre;
		while (fast && fast->next) {
			pre = slow;
			fast = fast->next->next;
			slow = slow->next;
		}
		pre->next = reverseList(slow);
		ListNode* forward = head;
		ListNode* backward = pre->next;
		while (forward != pre->next) {
			if (forward->val != backward->val) return false;
			forward = forward->next;
			backward = backward->next;
		}
		return true;
	}

	ListNode* reverseList(ListNode* head) {
		ListNode* pre = NULL;
		while (head) {
			ListNode* nxt = head->next;
			head->next = pre;
			pre = head;
			head = nxt;
		}
		return pre;
	}
};
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
	/** @param head The linked list's head.
	Note that the head is guaranteed to be not null, so it contains at least one node. */
	vector<int> nums;
	Solution(ListNode* head) {
		for (ListNode* node = head; node != NULL; node = node->next) {
			nums.push_back(node->val);
		}
	}

	/** Returns a random node's value. */
	int getRandom() {
		return nums[rand() % nums.size()];
	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(head);
* int param_1 = obj.getRandom();
*/
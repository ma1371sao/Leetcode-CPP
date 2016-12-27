/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		vector<int>nums;
		if (head == NULL)
			return NULL;
		ListNode *p = head;
		while (p)
		{
			nums.push_back(p->val);
			p = p->next;
		}
		int n = nums.size();
		int mid = (n - 1) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		Tree(nums, 0, mid - 1, root, 0);
		Tree(nums, mid + 1, n - 1, root, 1);
		return root;
	}
	void Tree(vector<int>& nums, int left, int right, TreeNode*p, int lr)
	{
		if (left>right)
			return;
		int mid = left + (right - left) / 2;
		if (lr == 0)
		{
			p->left = new TreeNode(nums[mid]);
			Tree(nums, left, mid - 1, p->left, 0);
			Tree(nums, mid + 1, right, p->left, 1);
		}
		else
		{
			p->right = new TreeNode(nums[mid]);
			Tree(nums, left, mid - 1, p->right, 0);
			Tree(nums, mid + 1, right, p->right, 1);
		}
	}
};
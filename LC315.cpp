struct Node {
	Node* left;
	Node* right;
	int val;
	int numLeft;
	int dup;
	Node(int v) : val(v), numLeft(0), dup(1), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		vector<int> counts(nums.size(), 0);
		if (nums.size() < 2) return counts;
		Node* root = new Node(nums.back());
		for (int i = nums.size() - 2; i >= 0; i--) {
			buildBST(root, nums[i], i, counts, 0);
		}
		return counts;
	}

	void buildBST(Node* root, int num, int index, vector<int>& counts, int count) {
		if (num < root->val) {
			root->numLeft++;
			if (root->left) buildBST(root->left, num, index, counts, count);
			else {
				root->left = new Node(num);
				counts[index] = count;
				return;
			}
		}
		else if (num > root->val) {
			if (root->right) buildBST(root->right, num, index, counts, count + root->dup + root->numLeft);
			else {
				root->right = new Node(num);
				counts[index] = count + root->dup + root->numLeft;
				return;
			}
		}
		else {
			root->dup++;
			counts[index] = count + root->numLeft;
		}
	}
};
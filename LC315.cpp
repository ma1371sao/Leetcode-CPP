// recursion
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
// loop
class Solution {
public:
    struct TreeNode {
        int val;
        int dup;
        int numLeft;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int v): val(v), left(NULL), right(NULL), numLeft(0), dup(0) {}
    };
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        if (nums.size() == 0) return counts;
        TreeNode* root = new TreeNode(nums.back());
        for (int i = n - 2; i >= 0; i--) {
            TreeNode* p = root;
            while (1) {
                if (nums[i] > p->val) {
                    counts[i] += p->numLeft + 1 + p->dup;
                    if (p->right) p = p->right;
                    else {
                        p->right = new TreeNode(nums[i]);
                        break;
                    }
                }
                else if (nums[i] < p->val) {
                    p->numLeft++;
                    if (p->left) p = p->left;
                    else {
                        p->left = new TreeNode(nums[i]);
                        break;
                    }
                }
                else {
                    counts[i] += p->numLeft;
                    p->dup++;
                    break;
                }
            }
        }
        return counts;
    }
};

vector<int> mergeTwoBST(TreeNode* root1, TreeNode* root2) {
    vector<int> ans;
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;
    TreeNode* cur1 = root1;
    TreeNode* cur2 = root2;
    while (!st1.empty() || cur1 || !st2.empty() || cur2) {
        while (cur1) {
            st1.push(cur1);
            cur1 = cur1->left;
        }
        
        while (cur2) {
            st2.push(cur2);
            cur2 = cur2->left;
        }
        
        if (!st1.empty() && !st2.empty()) {
            cur1 = st1.top();
            st1.pop();
            cur2 = st2.top();
            st2.pop();
            if (cur1->val <= cur2->val) {
                ans.push_back(cur1->val);
                ans.push_back(cur2->val);
            } else {
                ans.push_back(cur2->val);
                ans.push_back(cur1->val);
            }
            cur1 = cur1->right;
            cur2 = cur2->right;
        } else if (!st1.empty()) {
            cur1 = st1.top();
            st1.pop();
            ans.push_back(cur1->val);
            cur1 = cur1->right;
        } else if (!st2.empty()) {
            cur2 = st2.top();
            st2.pop();
            ans.push_back(cur2->val);
            cur2 = cur2->right;
        }
        
    }
    return ans;
}

int main() {
    TreeNode *root1 = new TreeNode(5); 
    root1->left = new TreeNode(4); 
    root1->left->left = new TreeNode(1); 
    root1->left->left->right  = new TreeNode(3); 
    root1->left->left->right->left = new TreeNode(2);
    
    TreeNode *root2 = new TreeNode(4);
    root2->left        = new TreeNode(2);
    root2->right       = new TreeNode(5);
    root2->left->left  = new TreeNode(1);
    root2->left->right = new TreeNode(3);
    
    auto ans = mergeTwoBST(root1, root2);
    for (int n : ans) cout << n << endl;
    
    root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(5);
    
    root2 = new TreeNode(4);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(6);
    ans = mergeTwoBST(root1, root2);
    for (int n : ans) cout << n << endl;
}

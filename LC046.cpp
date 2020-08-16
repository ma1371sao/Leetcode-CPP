class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> visited(nums.size(), false);
        vector<int> perm;
        dfs(nums, res, visited, perm);
        return res;
    }
    
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<bool>& visited, vector<int>& perm) {
        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                perm.push_back(nums[i]);
                visited[i] = true;
                dfs(nums, res, visited, perm);
                perm.pop_back();
                visited[i] = false;
            }
        }
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        findSubsets(res, v, nums, 0);
        return res;
    }
    
    void findSubsets(vector<vector<int>>& res, vector<int>& v, vector<int>& nums, int pos) {
        if (pos >= nums.size()) {
            res.push_back(v);
            return;
        }
        findSubsets(res, v, nums, pos + 1);
        v.push_back(nums[pos]);
        findSubsets(res, v, nums, pos + 1);
        v.pop_back();
    }
};
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        res.push_back(v);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int count = 1;
            for (; i + 1 < nums.size(), nums[i] == nums[i + 1]; i++, count++);
            int k = res.size();
            for (int j = 0; j < k; j++) {
                vector<int> sub = res[j];
                for (int c = 0; c < count; c++) {
                    sub.push_back(nums[i]);
                    res.push_back(sub);
                }
            }
        }
        return res;
    }
};
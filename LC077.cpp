class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> v;
        findCombine(res, v, n, k, 1);
        return res;
    }
    
    void findCombine(vector<vector<int>>& res, vector<int>& v, int n, int k, int pos) {
        if (k == 0) {
            res.push_back(v);
            return;
        }
        if (pos > n) return;
        v.push_back(pos);
        findCombine(res, v, n, k - 1, pos + 1);
        v.pop_back();
        findCombine(res, v, n, k, pos + 1);
    }
};
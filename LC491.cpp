class Solution {
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		set<vector<int>> subsequenceSet;
		vector<vector<int>> res;
		vector<int> subsequence;
		if (nums.size() < 2) return res;
		getSubsequence(nums, 0, subsequenceSet, subsequence);
		for (auto it = subsequenceSet.begin(); it != subsequenceSet.end(); it++) {
			res.push_back(*it);
		}
		return res;
	}

	void getSubsequence(vector<int>& nums, int index, set<vector<int>>& subsequenceSet, vector<int>& subsequence) {
		if (subsequence.size() > 1) subsequenceSet.insert(subsequence);
		for (int i = index; i < nums.size(); i++) {
			if (subsequence.size() == 0 || subsequence.back() <= nums[i]) {
				subsequence.push_back(nums[i]);
				getSubsequence(nums, i + 1, subsequenceSet, subsequence);
				subsequence.pop_back();
			}
		}
	}
};
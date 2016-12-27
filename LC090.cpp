class Solution {
public:
	vector<vector<int>> ans;
	unordered_map<string, int> m;
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		int n = nums.size();
		if (!n)  return ans;
		sort(nums.begin(), nums.end());
		DFS(nums, 0, "");
		return ans;
	}
	void DFS(vector<int>& nums, int pos, string subset) {
		if (pos == nums.size()) {
			if (m[subset] == 0) {
				m[subset] = 1;
				vector<int> v;
				for (int i = 0; i<subset.length(); i++)
					v.push_back(subset[i] - '0');
				ans.push_back(v);
			}
			return;
		}
		DFS(nums, pos + 1, subset);
		char c = '0' + nums[pos];
		DFS(nums, pos + 1, subset + c);
	}
};
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> ans;
		int a[1000000];
		DFS(nums, n, 0, ans, 0, a);
		return ans;
	}
	void DFS(vector<int>& nums, int n, int pos, vector<vector<int>>& ans, int num, int *a)
	{
		if (pos == n)
		{
			vector<int> v;
			for (int i = 0; i<num; i++)
				v.push_back(a[i]);
			ans.push_back(v);
			return;
		}
		a[num] = nums[pos];
		DFS(nums, n, pos + 1, ans, num + 1, a);
		DFS(nums, n, pos + 1, ans, num, a);
	}
};
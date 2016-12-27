class Solution {
public:
	vector<vector<int>> ans;
	int a[100000];
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		if (candidates.size() == 0)
			return ans;
		DFS(candidates, target, 0, 0, 0);
		return ans;
	}
	void DFS(vector<int>& candidates, int target, int sum, int pos, int num)
	{
		if (sum == target)
		{
			vector<int> v;
			for (int i = 0; i<num; i++)
				v.push_back(a[i]);
			ans.push_back(v);
			return;
		}
		if (pos == candidates.size())
			return;
		for (int i = 1; sum + candidates[pos] * i <= target; i++)
		{
			for (int j = num; j<i + num; j++)
				a[j] = candidates[pos];
			DFS(candidates, target, sum + candidates[pos] * i, pos + 1, num + i);
		}
		DFS(candidates, target, sum, pos + 1, num);
	}
};
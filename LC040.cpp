class Solution {
public:
	vector<vector<int>> ans;
	int a[100000];
	map<int, int> m;
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		if (candidates.size() == 0)
			return ans;
		sort(candidates.begin(), candidates.end());
		vector<int> can;
		for (int i = 0; i<candidates.size(); i++)
			if (m.find(candidates[i]) == m.end())
			{
				m[candidates[i]] = 1;
				can.push_back(candidates[i]);
			}
			else
				m[candidates[i]]++;
		DFS(can, target, 0, 0, 0);
		return ans;
	}
	void DFS(vector<int>& candidates, int target, int pos, int num, int sum)
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
		for (int i = 1; i <= m[candidates[pos]] && sum + candidates[pos] * i <= target; i++)
		{
			for (int j = num; j<num + i; j++)
				a[j] = candidates[pos];
			DFS(candidates, target, pos + 1, num + i, sum + candidates[pos] * i);
		}
		DFS(candidates, target, pos + 1, num, sum);
	}
};
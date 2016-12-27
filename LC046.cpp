class Solution {
public:
	vector<vector<int>> ans;
	int vis[100];
	int a[100];
	vector<vector<int>> permute(vector<int>& nums) {
		if (nums.size() == 0)
			return ans;
		//sort(nums.begin(),nums.end());
		for (int i = 0; i<nums.size(); i++)  vis[i] = 0;
		DFS(nums, 0);
		return ans;
	}
	void DFS(vector<int>& nums, int pos)
	{
		if (pos == nums.size())
		{
			vector<int> v;
			for (int i = 0; i<pos; i++)
				v.push_back(a[i]);
			ans.push_back(v);
			return;
		}
		for (int i = 0; i<nums.size(); i++)
		{
			if (vis[i] == 1)
				continue;
			else
			{
				a[pos] = nums[i];
				vis[i] = 1;
				DFS(nums, pos + 1);
				vis[i] = 0;
			}
		}
	}
};
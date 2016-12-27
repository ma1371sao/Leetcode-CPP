class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> ans;
		if (k>n)
			return ans;
		int a[100000];
		DFS(0, 1, n, k, a, ans);
		return ans;
	}
	void DFS(int num, int pos, int n, int k, int a[], vector<vector<int>>& ans)
	{
		if (num == k)
		{
			vector<int> v;
			for (int i = 0; i<k; i++)
				v.push_back(a[i]);
			ans.push_back(v);
			return;
		}
		if (pos>n)
			return;
		a[num] = pos;
		DFS(num + 1, pos + 1, n, k, a, ans);
		DFS(num, pos + 1, n, k, a, ans);
	}
};
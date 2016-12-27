class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ans;
		if (numRows == 0)
			return ans;
		vector<int> v;
		v.push_back(1);
		ans.push_back(v);
		if (numRows == 1)
			return ans;
		v.push_back(1);
		ans.push_back(v);
		if (numRows == 2)
			return ans;
		for (int i = 2; i<numRows; i++)
		{
			vector<int> v;
			v.push_back(1);
			for (int j = 0; j<ans[i - 1].size() - 1; j++)
			{
				v.push_back(ans[i - 1][j] + ans[i - 1][j + 1]);
			}
			v.push_back(1);
			ans.push_back(v);
		}
		return ans;
	}
};
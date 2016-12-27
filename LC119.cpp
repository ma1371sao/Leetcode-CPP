class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> ans;
		ans.push_back(1);
		if (rowIndex == 0)
			return ans;
		ans.push_back(1);
		if (rowIndex == 1)
			return ans;
		for (int i = 2; i <= rowIndex; i++)
		{
			int tem1 = 1;
			int tem2;
			for (int j = 1; j<ans.size(); j++)
			{
				tem2 = ans[j];
				ans[j] = tem1 + ans[j];
				tem1 = tem2;
			}
			ans.push_back(1);
		}
		return ans;
	}
};
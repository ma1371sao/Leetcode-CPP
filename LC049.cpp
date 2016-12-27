class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		if (strs.size() == 0)
			return res;
		map<string, int> m;
		int n = 0;
		for (int i = 0; i<strs.size(); i++)
		{
			string s = strs[i];
			sort(s.begin(), s.end());
			if (m.find(s) == m.end())
			{
				m[s] = n;
				n++;
				vector<string> v;
				v.push_back(strs[i]);
				res.push_back(v);
			}
			else
			{
				res[m[s]].push_back(strs[i]);
			}
		}
		return res;
	}
};
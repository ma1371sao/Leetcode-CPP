class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> ans;
		if (s.length() == 0)
			return ans;
		if (words.size() == 0 || words[0].length() == 0)
			return ans;
		map<string, int> mp;
		int n, m, l;
		n = words.size();
		m = words[0].length();
		l = s.length();
		int tl = n*m;
		if (tl>l)
			return ans;
		int flag = 1;
		for (int i = 0; i<n; i++)
			mp[words[i]]++;
		for (int i = 0; i<l - tl + 1; i++)
		{
			map<string, int> mm(mp);
			flag = 1;
			int num = 0;
			int sublen = i + tl;
			for (int k = i; k<sublen && flag; k = k + m)
			{
				string ss = s.substr(k, m);
				if (mp.find(ss) == mp.end())
				{
					flag = 0;
					break;
				}
				else
				{
					mm[ss]--;
					num++;
					if (mm[ss]<0)
					{
						flag = 0;
						break;
					}
				}
			}
			if (flag && num == n)
				ans.push_back(i);
		}
		return ans;
	}
};
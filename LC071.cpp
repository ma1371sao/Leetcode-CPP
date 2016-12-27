class Solution {
public:
	string simplifyPath(string path) {
		int n = path.length();
		string ans;
		int pos, end;
		pos = path.find('/', 0);
		ans.push_back('/');
		while (pos<n - 1)
		{
			end = path.find('/', pos + 1);
			if (end == string::npos)
				end = n;
			string s = path.substr(pos + 1, end - pos - 1);
			if (s == "..")
			{
				int k = ans.size() - 1;
				while (ans[k] == '/')
					k--;
				while (ans[k] != '/')
					k--;
				ans = ans.substr(0, k);
				if (ans.size() == 0)
					ans.push_back('/');
			}
			else if (s != ".")
				for (int i = pos; i<end; i++)
					ans.push_back(path[i]);
			pos = end;
		}
		string res;
		for (int i = 0; i<ans.length(); i++)
		{
			res.push_back(ans[i]);
			if (ans[i] == '/')
				while (i + 1<ans.length() && ans[i + 1] == '/') i++;
		}
		if (res[res.size() - 1] == '/' && res.size()>1)
			res = res.substr(0, res.size() - 1);
		return res;
	}
};
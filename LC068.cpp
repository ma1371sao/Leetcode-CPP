class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> ans;
		int n = words.size();
		if (n == 0)
		{
			string s;
			for (int i = 0; i<maxWidth; i++)
				s.push_back(' ');
			ans.push_back(s);
			return ans;
		}
		int pos = 0;
		while (pos<n)
		{
			int start = pos;
			string s;
			int l = 0;
			int num = 0;
			while (pos<n && l + words[pos].length() <= maxWidth)
			{
				if (num>0)
					if (l + words[pos].length() + 1>maxWidth)
						break;
					else
						l++;
				l = l + words[pos].length();
				pos++;
				num++;
			}
			if (num == 1)
			{
				s = words[pos - 1];
				for (int i = words[pos - 1].size(); i<maxWidth; i++)
					s.push_back(' ');
			}
			else if (pos == n)
			{
				for (int i = 0; i<num; i++)
				{
					for (int j = 0; j<words[start + i].size(); j++)
						s.push_back(words[start + i][j]);
					if (i != num - 1)
						s.push_back(' ');
				}
				for (int i = l; i<maxWidth; i++)
					s.push_back(' ');
			}
			else
			{
				int p = (maxWidth - l) / (num - 1);
				int q = (maxWidth - l) % (num - 1);
				for (int i = start; i<pos; i++)
				{
					if (i>start)
						s.push_back(' ');
					for (int j = 0; j<words[i].size(); j++)
						s.push_back(words[i][j]);
					if (i != pos - 1)
					{
						for (int j = 0; j<p; j++)
							s.push_back(' ');
						if (q>0)
						{
							s.push_back(' ');
							q--;
						}
					}
				}
			}
			ans.push_back(s);
		}
		return ans;
	}
};
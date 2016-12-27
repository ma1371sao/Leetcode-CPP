class Solution {
public:
	string minWindow(string s, string t) {
		int ns = s.length();
		int nt = t.length();
		if (ns == 0 || nt == 0 || ns<nt)
			return "";
		map<char, int> mt;
		for (int i = 0; i<nt; i++)
			mt[t[i]]++;
		map<char, int> ms;
		int pos = 0;
		int min = ns + 1;
		int start;
		queue<int> q;
		int num = nt;
		for (pos = 0; pos <= ns - nt; pos++)
			if (mt.find(s[pos]) != mt.end())
				break;
		if (pos == ns - nt + 1)
			return "";
		ms[s[pos]]++;
		num--;
		q.push(pos);
		start = pos;
		int l;
		pos++;
		while (!q.empty())
		{
			l = pos - q.front();
			while (pos<ns && num>0 && l<min)
			{
				if (mt.find(s[pos]) != mt.end())
				{
					ms[s[pos]]++;
					if (ms[s[pos]] <= mt[s[pos]])
						num--;
					q.push(pos);
				}
				pos++;
				l++;
			}
			if (num == 0)
			{
				if (l<min)
				{
					min = l;
					start = q.front();
				}
				ms[s[q.front()]]--;
				if (ms[s[q.front()]]<mt[s[q.front()]])
					num++;
				q.pop();
			}
			else if (l == min)
			{
				ms[s[q.front()]]--;
				if (ms[s[q.front()]]<mt[s[q.front()]])
					num++;
				q.pop();
			}
			else
			{
				break;
			}
		}
		if (min == ns + 1)
			return "";
		string ans;
		for (int i = start; i<start + min; i++)
			ans.push_back(s[i]);
		return ans;
	}
};
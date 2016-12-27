class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int ans = 0;
		int l = s.length();
		if (l == 0)
			return ans;
		map<char, int> m;
		int max = 0;
		int start = 0;
		for (int i = 0; i<l; i++)
		{
			if (m.find(s[i]) == m.end() || m[s[i]]<start)
			{
				m[s[i]] = i;
				max++;
			}
			else
			{
				if (max>ans)
					ans = max;
				max = i - m[s[i]];
				start = m[s[i]] + 1;
				m[s[i]] = i;
			}
		}
		if (max>ans)
			ans = max;
		return ans;
	}
};
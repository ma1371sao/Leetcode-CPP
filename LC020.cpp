class Solution {
public:
	bool isValid(string s) {
		int l = s.length();
		stack<char> st;
		map<char, char> m;
		m['('] = ')';
		m['['] = ']';
		m['{'] = '}';
		m[')'] = '(';
		m[']'] = '[';
		m['}'] = '{';
		for (int i = 0; i<l; i++)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				st.push(s[i]);
			else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
			{
				if (!st.empty())
				{
					if (st.top() == m[s[i]])
					{
						st.pop();
					}
					else
						return false;
				}
				else
					return false;
			}
		}
		if (st.empty())
			return true;
		else
			return false;
	}
};
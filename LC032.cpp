class Solution {
public:
	int longestValidParentheses(string s) {
		int ans = 0;
		if (s.length() == 0 || s.length() == 1)
			return ans;
		stack<int> st;
		int arr[100000];
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i<s.length(); i++)
		{
			if (s[i] == '(')
				st.push(i);
			else
			{
				if (!st.empty())
				{
					arr[st.top()] = 1;
					arr[i] = 1;
					st.pop();
				}
			}
		}
		int k = 0;
		int max = 0;
		while (k<s.length())
		{
			if (arr[k] == 1)
			{
				max++;
				k++;
			}
			else
			{
				if (ans<max)
					ans = max;
				max = 0;
				for (; arr[k] == 0; k++);
			}
		}
		if (max>ans)
			ans = max;
		return ans;
	}
};
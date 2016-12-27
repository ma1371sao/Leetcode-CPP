class Solution {
public:
	vector<string> ans;
	int a[1000000];
	queue<char> q;
	vector<string> generateParenthesis(int n) {
		if (n == 0)
			return ans;
		DFS(n, 0, 0, 0);
		return ans;
	}
	void DFS(int n, int front, int back, int pos)
	{
		if (front == n && back == n)
		{
			string s;
			for (int i = 0; i<2 * n; i++)
				if (a[i] == 1)
					s.push_back('(');
				else
					s.push_back(')');
			ans.push_back(s);
			return;
		}
		if (front<n)
		{
			a[pos] = 1;
			DFS(n, front + 1, back, pos + 1);
		}
		if (back<front && back<n)
		{
			a[pos] = -1;
			DFS(n, front, back + 1, pos + 1);
		}
	}
};
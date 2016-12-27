class Solution {
public:
	string convertToTitle(int n) {
		string ans;
		int x;
		char c;
		do
		{
			n--;
			x = n % 26;
			n = n / 26;
			c = 'A' + x;
			string tmp;
			tmp = c + ans;
			ans = tmp;
		} while (n != 0);
		return ans;
	}
};
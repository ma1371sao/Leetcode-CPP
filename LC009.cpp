class Solution {
public:
	bool isPalindrome(int x) {
		string s;
		int a, b = x;
		if (x<0)
			return false;
		do
		{
			a = b % 10;
			s.push_back(a + 48);
			b = b / 10;
		} while (b);
		int l = s.size();
		int reserve = 0;
		for (int i = 0; i<l; i++)
		{
			reserve = reserve * 10 + s[i] - 48;
		}
		if (reserve == x)
			return true;
		else
			return false;
	}
};
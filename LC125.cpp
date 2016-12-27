class Solution {
public:
	bool isPalindrome(string s) {
		if (s.length() == NULL)
			return true;
		int l = s.length();
		int i, j;
		for (i = 0, j = l - 1; i<j; i++, j--)
		{
			while (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) && i<l) i++;
			while (!((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= '0' && s[j] <= '9')) && j >= 0) j--;
			if (i >= j)
				break;
			if (s[i]>s[j])
			{
				if (s[j]<'A' || s[i]>'z')
					return false;
				if (s[j] + 32 != s[i])
					return false;
			}
			else if (s[i]<s[j])
			{
				if (s[i]<'A' || s[j]>'z')
					return false;
				if (s[i] + 32 != s[j])
					return false;
			}
		}
		return true;
	}
};
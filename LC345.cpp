class Solution {
public:
	string reverseVowels(string s) {
		int l = s.length();
		int i = 0;
		int j = l - 1;
		string ans = s;
		for (; i<j; i++)
		{
			if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u' || ans[i] == 'A' || ans[i] == 'E' || ans[i] == 'I' || ans[i] == 'O' || ans[i] == 'U')
				for (; j>i; j--)
					if (ans[j] == 'A' || ans[j] == 'E' || ans[j] == 'I' || ans[j] == 'O' || ans[j] == 'U' || ans[j] == 'a' || ans[j] == 'e' || ans[j] == 'i' || ans[j] == 'o' || ans[j] == 'u')
					{
						char tmp = ans[j];
						ans[j] = ans[i];
						ans[i] = tmp;
						j--;
						break;
					}
		}
		return ans;
	}
};
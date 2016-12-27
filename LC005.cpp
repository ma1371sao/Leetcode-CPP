class Solution {
public:
	string longestPalindrome(string s) {
		int l = s.length();
		int mid;
		string ans;
		int left = 0;
		int right = l - 1;
		int ans_start = 0;
		int ans_length = 0;
		for (int lp = 0; lp<l; lp++)
		{
			if ((right - lp + 1) % 2 == 1)
			{
				mid = lp + (right - lp) / 2;
				int num = 1;
				for (int i = 1; mid + i<l; i++)
					if (s[mid + i] == s[mid - i])
						num += 2;
					else
						break;
				if (num>ans_length)
				{
					ans_length = num;
					ans_start = mid - (num - 1) / 2;
				}
			}
			if ((right - lp + 1) % 2 == 0)
			{
				int num;
				mid = lp + (right - lp - 1) / 2;
				if (s[mid] == s[mid + 1])
				{
					num = 2;
					for (int i = 1; mid + 1 + i<l; i++)
						if (s[mid + 1 + i] == s[mid - i])
							num = num + 2;
						else
							break;
					if (num>ans_length)
					{
						ans_length = num;
						ans_start = mid - (num - 2) / 2;
					}
				}
			}
		}
		for (int rp = l - 1; rp >= 0; rp--)
		{
			if ((rp - left + 1) % 2 == 1)
			{
				mid = left + (rp - left) / 2;
				int num = 1;
				for (int i = 1; mid - i >= 0; i++)
					if (s[mid + i] == s[mid - i])
						num = num + 2;
					else
						break;
				if (num>ans_length)
				{
					ans_length = num;
					ans_start = mid - (num - 1) / 2;
				}
			}
			if ((rp - left + 1) % 2 == 0)
			{
				int num;
				mid = left + (rp - left - 1) / 2;
				if (s[mid] == s[mid + 1])
				{
					num = 2;
					for (int i = 1; mid - i >= 0; i++)
						if (s[mid + 1 + i] == s[mid - i])
							num = num + 2;
						else
							break;
					if (num>ans_length)
					{
						ans_length = num;
						ans_start = mid - (num - 2) / 2;
					}
				}
			}
		}
		for (int i = 0; i<ans_length; i++)
			ans.push_back(s[ans_start + i]);
		return ans;
	}
};
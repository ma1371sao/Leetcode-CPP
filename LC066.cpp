class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int l = digits.size();
		int flag = 1;
		for (int i = l - 1; i >= 0; i--)
		{
			digits[i] += flag;
			if (digits[i]>9)
			{
				digits[i] -= 10;
				flag = 1;
			}
			else
				flag = 0;
		}
		if (flag == 1)
		{
			vector<int> ans;
			ans.push_back(flag);
			for (int i = 0; i<l; i++)
				ans.push_back(digits[i]);
			return ans;
		}
		else
			return digits;
	}
};
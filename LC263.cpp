class Solution {
public:
	vector<int> prime;
	bool isUgly(int num) {
		if (num == 1 || num == 4 || num == 2 || num == 3 || num == 5)
			return true;
		if (num<1)
			return false;
		int n = num;
		while (n != 1)
		{
			if (n % 2 == 0)
				n = n / 2;
			else if (n % 3 == 0)
				n = n / 3;
			else if (n % 5 == 0)
				n = n / 5;
			else
				return false;
		}
		return true;
	}
};
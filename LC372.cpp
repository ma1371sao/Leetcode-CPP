class Solution {
public:
	int power(int a, int b) {
		int res = 1;
		a = a % 1337;
		for (int i = 0; i<b; i++)
			res = (res*a) % 1337;
		return res;
	}
	int superPow(int a, vector<int>& b) {
		if (a == 0 || a == 1)    return a;
		if (b.size() == 0)
			return 1;
		int n = b.back();
		b.pop_back();
		return (power(a, n)*power(superPow(a, b) % 1337, 10)) % 1337;
	}
};
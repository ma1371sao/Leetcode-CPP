class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> un;
		un.push_back(1);
		int k2 = 0;
		int k3 = 0;
		int k5 = 0;
		while (un.size()<n) {
			int min = minnum(un[k2] * 2, un[k3] * 3, un[k5] * 5);
			un.push_back(min);
			if (min == un[k2] * 2)   k2++;
			if (min == un[k3] * 3)   k3++;
			if (min == un[k5] * 5)   k5++;
		}
		return un.back();
	}
	int minnum(int a, int b, int c) {
		int min = a;
		if (b<min)   min = b;
		if (c<min)   min = c;
		return min;
	}
};
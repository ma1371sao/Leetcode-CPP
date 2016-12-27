class Solution {
public:
	int maxRotateFunction(vector<int>& A) {
		int n = A.size();
		if (n == 0)
			return 0;
		int max;
		int ini = 0;
		int p = 0;
		for (int i = 0; i<n; i++)
		{
			ini = ini + p*A[i];
			p++;
		}
		max = ini;
		int inc = 0;
		for (int i = 0; i<n; i++)
			inc = inc + A[i];
		for (int i = 1; i<n; i++)
		{
			ini = ini + inc - n*A[n - i];
			if (ini>max)
				max = ini;
		}
		return max;
	}
};
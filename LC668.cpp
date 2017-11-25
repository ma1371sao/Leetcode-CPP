class Solution {
public:
	int findKthNumber(int m, int n, int k) {
		int low = 1;
		int high = m * n;
		while (low < high) {
			int mid = low + (high - low) / 2;
			int numLEMid = count(mid, m, n);
			if (numLEMid >= k) high = mid;
			else low = mid + 1;
		}
		return low;
	}

	int count(int target, int m, int n) {
		int num = 0;
		for (int i = 1; i <= m; i++) {
			num += min(target / i, n);
		}
		return num;
	}
};
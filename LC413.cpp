class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		int num = 0;
		if (A.size() < 3) return 0;
		int slow = 1;
		bool isSlice = false;
		int fast;
		for (fast = 2; fast < A.size(); fast++) {
			if (A[fast] - A[fast - 1] == A[slow] - A[slow - 1]) {
				isSlice = true;
			}
			else {
				if (isSlice) {
					int n = fast - (slow - 1);
					num += (n - 2) * (n - 1) / 2;
					isSlice = false;
					slow = fast;
				}
				else {
					slow = fast;
				}
			}
		}
		if (isSlice) {
			int n = fast - (slow - 1);
			num += (n - 2) * (n - 1) / 2;
		}
		return num;
	}
};
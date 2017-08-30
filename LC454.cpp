class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		if (A.size() == 0) return 0;
		unordered_map<int, int> sumAB;
		int num = 0;
		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < B.size(); j++) {
				sumAB[A[i] + B[j]]++;
			}
		}
		for (int i = 0; i < C.size(); i++) {
			for (int j = 0; j < D.size(); j++) {
				int sum = -1 * (C[i] + D[j]);
				if (sumAB.find(sum) != sumAB.end()) {
					num += sumAB[sum];
				}
			}
		}
		return num;
	}
};
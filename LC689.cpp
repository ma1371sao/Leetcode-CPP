class Solution {
public:
	vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
		int n = nums.size();
		vector<int> startPos(3, 0);
		if (k == 0) return startPos;
		vector<int> ksums(n, 0);
		vector<int> left(n, 0);
		vector<int> posLeft(n, 0);
		vector<int> right(n, 0);
		vector<int> posRight(n, 0);
		int maxSum = 0;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += nums[i];
			if (i >= k - 1) {
				ksums[i] = sum;
				sum -= nums[i - k + 1];
				if (i == k - 1) {
					left[i] = ksums[i];
					posLeft[i] = 0;
					continue;
				}
				if (left[i - 1] >= ksums[i]) {
					left[i] = left[i - 1];
					posLeft[i] = posLeft[i - 1];
				}
				else {
					left[i] = ksums[i];
					posLeft[i] = i - k + 1;
				}
			}
		}
		right[n - k] = ksums[n - 1];
		posRight[n - k] = n - k;
		for (int i = n - k - 1; i >= 2 * k; i--) {
			if (right[i + 1] > ksums[i + k - 1]) {
				right[i] = right[i + 1];
				posRight[i] = posRight[i + 1];
			}
			else {
				right[i] = ksums[i + k - 1];
				posRight[i] = i;
			}
		}
		for (int i = k; i <= n - 2 * k; i++) {
			if (maxSum < left[i - 1] + ksums[i + k - 1] + right[i + k]) {
				startPos[0] = posLeft[i - 1];
				startPos[1] = i;
				startPos[2] = posRight[i + k];
				maxSum = left[i - 1] + ksums[i + k - 1] + right[i + k];
			}
		}
		return startPos;
	}
};
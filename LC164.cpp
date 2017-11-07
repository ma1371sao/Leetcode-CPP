class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size() < 2) return 0;
		int maxVal = INT_MIN;
		int minVal = INT_MAX;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			maxVal = max(maxVal, nums[i]);
			minVal = min(minVal, nums[i]);
		}
		vector<int> gapMax(n - 1, INT_MIN);
		vector<int> gapMin(n - 1, INT_MAX);
		int gap = ceil((maxVal - minVal) * 1.0 / (n - 1));
		if (gap == 0) return 0;
		for (int i = 0; i < n; i++) {
			if (nums[i] == minVal || nums[i] == maxVal) continue;
			int k = (nums[i] - minVal) / gap;
			gapMax[k] = max(gapMax[k], nums[i]);
			gapMin[k] = min(gapMin[k], nums[i]);
		}
		int pre = minVal;
		int maxGap = 0;
		for (int i = 0; i < n - 1; i++) {
			if (gapMin[i] < INT_MAX && gapMax[i] > INT_MIN) {
				maxGap = max(gapMin[i] - pre, maxGap);
				pre = gapMax[i];
			}
		}
		maxGap = max(maxGap, maxVal - pre);
		return maxGap;
	}
};
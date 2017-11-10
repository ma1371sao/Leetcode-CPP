class Solution {
public:
	int smallestDistancePair(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int left = 0;
		int right = nums.back();
		while (left < right) {
			int mid = left + (right - left) / 2;
			int numBetIJ = 0;
			for (int i = 0, j = 0; i < nums.size(); i++) {
				while (j < nums.size() && nums[j] - nums[i] <= mid)
					j++;
				numBetIJ += j - i - 1;
			}
			if (numBetIJ >= k)
				right = mid;
			if (numBetIJ < k)
				left = mid + 1;
		}
		return left;
	}
};
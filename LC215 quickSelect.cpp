class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int n = nums.size();
		return quickSelect(nums, 0, n - 1, n - k + 1);
	}

	int quickSelect(vector<int>& nums, int l, int r, int k) {
		int stdNum = nums[l];
		int i = l + 1;
		int j = r;
		while (i <= j) {
			if (nums[j] <= stdNum) {
				int tmp = nums[j];
				nums[j] = nums[i];
				nums[i++] = tmp;
			}
			else j--;
		}
		nums[l] = nums[j];
		nums[j] = stdNum;
		if (j - l + 1 == k) return nums[j];
		if (j - l + 1 > k) return quickSelect(nums, l, j - 1, k);
		else return quickSelect(nums, j + 1, r, k - (j - l + 1));
	}
};
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int mid = nums[n / 2];
		vector<int> res(n);
		int i, j;
		i = 0;
		j = n - 1;
		for (; j >= 0; j--) {
			if (j % 2 == 0) {
				if (nums[i]<mid)
					res[j] = nums[i++];
				else
					res[j] = mid;
			}
		}
		i = n - 1;
		j = 1;
		for (; j<n; j = j + 2)
			if (nums[i]>mid)
				res[j] = nums[i--];
			else
				res[j] = mid;
		nums = res;
	}
};
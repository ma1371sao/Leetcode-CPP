class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		int t = m + n;
		int me;
		int flag = 0;
		double ans;
		vector<int> nums = nums1;
		if (t % 2)
		{
			me = (t + 1) / 2;
			flag = 1;
		}
		else
			me = t / 2;
		for (int i = 0; i<n; i++)
			nums.push_back(nums2[i]);
		sort(nums.begin(), nums.end());
		if (flag)
			ans = nums[me - 1];
		else
			ans = (nums[me - 1] + nums[me]) / 2.0;
		return ans;
	}
};
class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return 0;
		int start, end;
		int min = INT_MAX;
		start = 0;
		end = 0;
		int sum = 0;
		while (end<n)
		{
			for (; end<n && sum<s; end++)
				sum = sum + nums[end];
			if (sum<s)
				break;
			if (end - start<min)
				min = end - start;
			for (; start<end && sum >= s; start++)
				sum = sum - nums[start];
			if (end - start + 1<min)
				min = end - start + 1;
		}
		if (min>n)
			return 0;
		return min;
	}
};
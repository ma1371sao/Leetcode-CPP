class Solution {
public:
	int trap(vector<int>& height) {
		if (height.size() == 0)
			return 0;
		int ans = 0;
		int n = height.size();
		int left[100000];
		int right[100000];
		left[0] = 0;
		right[n - 1] = 0;
		for (int i = 1; i<n; i++)
		{
			if (height[i - 1]>left[i - 1])
				left[i] = height[i - 1];
			else
				left[i] = left[i - 1];
		}
		for (int i = n - 2; i >= 0; i--)
		{
			if (height[i + 1]>right[i + 1])
				right[i] = height[i + 1];
			else
				right[i] = right[i + 1];
		}
		for (int i = 0; i<n; i++)
		{
			int min = 0;
			if (left[i] <= right[i])
				min = left[i];
			else
				min = right[i];
			if (min <= height[i])
				continue;
			ans = ans + min - height[i];
		}
		return ans;
	}
};
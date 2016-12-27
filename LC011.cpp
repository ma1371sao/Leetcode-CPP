class Solution {
public:
	int maxArea(vector<int>& height) {
		int n = height.size();
		int i = 0;
		int j = n - 1;
		int S = 0;
		while (i<j)
		{
			if (height[i] >= height[j])
			{
				if (height[j] * (j - i)>S)
					S = height[j] * (j - i);
				int tmp = height[j];
				for (; height[j] <= tmp && j>i; j--);
			}
			else
			{
				if (height[i] * (j - i)>S)
					S = height[i] * (j - i);
				int tmp = height[i];
				for (; height[i] <= tmp && i<j; i++);
			}
		}
		return S;
	}
};
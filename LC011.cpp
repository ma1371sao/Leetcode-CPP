class Solution {
public:
	int maxArea(vector<int>& height) {
		int left = 0;
		int right = height.size() - 1;
		int water = 0;
		while (left < right) {
			int h = min(height[left], height[right]);
			water = max(water, (right - left) * h);
			for (; left < right && height[left] <= h; left++);
			for (; left < right && height[right] <= h; right--);
		}
		return water;
	}
};
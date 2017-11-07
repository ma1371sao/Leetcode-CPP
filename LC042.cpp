class Solution {
public:
	int trap(vector<int>& height) {
		int maxHeight = 0;
		int index = 0;
		int total = 0;
		int cur = 0;
		for (int i = 0; i < height.size(); i++) {
			if (height[i] >= maxHeight) {
				total += cur;
				cur = 0;
				maxHeight = height[i];
				index = i;
			}
			else {
				cur += maxHeight - height[i];
			}
		}
		cur = 0;
		maxHeight = 0;
		for (int i = height.size() - 1; i >= index; i--) {
			if (height[i] >= maxHeight) {
				total += cur;
				cur = 0;
				maxHeight = height[i];
			}
			else {
				cur += maxHeight - height[i];
			}
		}
		return total;
	}
};
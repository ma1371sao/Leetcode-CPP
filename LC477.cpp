class Solution {
public:
	int totalHammingDistance(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int totalDis = 0;
		for (int i = 0; i < 32; i++) {
			int numOne = 0;
			for (int j = 0; j < nums.size(); j++) {
				if (0x01 & (nums[j] >> i)) {
					numOne++;
				}
			}
			totalDis += numOne * (nums.size() - numOne);
		}
		return totalDis;
	}
};
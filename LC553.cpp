class Solution {
public:
	string optimalDivision(vector<int>& nums) {
		string maxDivide;
		if (nums.size() == 0) return maxDivide;
		if (nums.size() == 1) return to_string(nums[0]);
		if (nums.size() == 2) return to_string(nums[0]) + "/" + to_string(nums[1]);
		for (int i = 0; i < nums.size(); i++) {
			maxDivide += to_string(nums[i]);
			if (i != nums.size() - 1)
				maxDivide += "/";
			else
				maxDivide += ")";
			if (i == 0)
				maxDivide += "(";
		}
		return maxDivide;
	}
};
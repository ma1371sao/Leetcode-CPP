class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		vector<int> res;
		if (findNums.size() == 0 || nums.size() == 0) return res;
		vector<int> rightGreaterNumIndex(nums.size(), -1);
		unordered_map<int, int> numIndex;
		numIndex[nums.back()] = nums.size() - 1;
		for (int i = nums.size() - 2; i >= 0; i--) {
			numIndex[nums[i]] = i;
			int right = i + 1;
			while (!(right == -1 || nums[right] > nums[i])) {
				right = rightGreaterNumIndex[right];
			}
			rightGreaterNumIndex[i] = right;
		}
		for (int i = 0; i < findNums.size(); i++) {
			if (rightGreaterNumIndex[numIndex[findNums[i]]] == -1)
				res.push_back(-1);
			else
				res.push_back(nums[rightGreaterNumIndex[numIndex[findNums[i]]]]);
		}
		return res;
	}
};
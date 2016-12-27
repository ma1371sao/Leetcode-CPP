class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int i, j;
		vector<int> res;
		if (numbers.size()<2)   return res;
		for (i = 0, j = numbers.size() - 1; i<j;) {
			if (numbers[i] + numbers[j] == target) {
				res.push_back(i + 1);
				res.push_back(j + 1);
				return res;
			}
			else if (numbers[i] + numbers[j]>target) {
				j--;
			}
			else {
				i++;
			}
		}
		return res;
	}
};
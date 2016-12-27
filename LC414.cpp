class Solution {
public:
	int thirdMax(vector<int>& nums) {
		long long t = INT_MIN;
		long long maxst = t - 1;
		long long maxrd = t - 1;
		long long maxnd = t - 1;
		for (int i = 0; i<nums.size(); i++) {
			if (nums[i]>maxst) {
				maxrd = maxnd;
				maxnd = maxst;
				maxst = nums[i];
			}
			else if (nums[i]>maxnd && nums[i]<maxst) {
				maxrd = maxnd;
				maxnd = nums[i];
			}
			else if (nums[i]>maxrd && nums[i]<maxnd) {
				maxrd = nums[i];
			}
		}
		if (maxrd<INT_MIN)  return maxst;
		return maxrd;
	}
};
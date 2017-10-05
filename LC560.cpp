class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int num = 0;
		if (nums.size() == 0) return 0;
		unordered_map<int, int> sum_times;
		sum_times[0] = 1;
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			if (sum_times.find(sum - k) != sum_times.end())
				num += sum_times[sum - k];
			sum_times[sum]++;
		}
		return num;
	}
};